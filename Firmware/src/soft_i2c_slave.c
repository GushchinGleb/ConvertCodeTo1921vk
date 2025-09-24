#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/soft_i2c_slave.h"

#include <stdint.h>
#include <stdbool.h>

#include "K1921VK035.h"

#define CHECK_ADDR(addr) ((addr & 0xFC) == 0xA0) // addr=[0xA0;0xA3]
#define GET_PAGE(addr)   (addr & 0xFE) //  addr=[0xA0;0xA3] -> page={0xA0;0xA2}

#define GPIOSDA GPIOA
#define SDA_PIN PIN5
#define SDA_PIN_MASK (1 << 5)

#define GPIOSCL GPIOA
#define SCL_PIN PIN4
#define SCL_PIN_MASK (1 << 4)

typedef enum {
  I2C_IDLE,
  I2C_RECEIVING_ADDR,
  I2C_RECEIVING_DATA,
  I2C_SENDING_DATA,
  I2C_ACK_PHASE,
  I2C_STOP
} i2c_state_t;

extern uint8_t* I2C_Data_Pointer; // from soft_i2c_api.c

static volatile i2c_state_t i2c_state = I2C_IDLE;
static volatile uint8_t bit_count = 0;
static volatile uint8_t current_byte = 0;
static volatile bool rw_flag = false; // 0 = master write, 1 = master read

/*
 The controller accept all incomming data for any destination address.
 It saves the addres for future use in I2C_Write_data or I2C_Read_data API funtions.
*/
static uint8_t I2C_Current_Address = 0;
/*
 The number of the page. 0xA0 is for A0 page structure, same for 0xA2.
*/
static uint8_t I2C_Current_Page = 0;

static uint8_t read_SDA(void);
static uint8_t read_SCL(void);
static void drive_SDA_low(void);
static void release_SDA(void);

void soft_I2C_init(void) {
	GPIOSDA->DRIVEMODE_bit.SDA_PIN = 0x2; // 10 - low power, high speed [213]
	GPIOSCL->DRIVEMODE_bit.SCL_PIN = 0x2; // 10 - low power, high speed [213]
	
	GPIOSDA->INTENSET_bit.SDA_PIN   = 0x1; // enable SDA iinterrup [page 219]
	GPIOSDA->INTTYPESET_bit.SDA_PIN = 0x1; // by front [page 220]
	GPIOSDA->INTEDGESET_bit.SDA_PIN = 0x1; // by both raise and fall [page 222]
	
	GPIOSCL->INTENSET_bit.SCL_PIN   = 0x1; // enable SCL iinterrup [page 219]
	GPIOSCL->INTTYPESET_bit.SCL_PIN = 0x1; // by front [page 220]
	GPIOSCL->INTPOLSET_bit.SCL_PIN  = 0x1; // by raise [page 221]
}

static void drive_SDA_low(void) {
  /* open-drain output */
	GPIOSDA->OUTMODE_bit.SDA_PIN = 0x1; // Open Drain [page 212]
	GPIOSDA->OUTENSET_bit.SDA_PIN = 1;  // output enable [page 213]
}

static void release_SDA(void) {
	/* input/floating */
	GPIOSDA->OUTENSET_bit.SDA_PIN = 0; // output disable, Z-state [page 213]
	GPIOSDA->DENSET_bit.SDA_PIN = 0x0; // push pull [page 212]
	GPIOSDA->INMODE_bit.SDA_PIN = 0x0; // Schmit trigger [page 51], [page 9], [page 211]
}

static uint8_t read_SDA(void) {
  return !!(GPIOSDA->DATA & SDA_PIN_MASK);
}

static uint8_t read_SCL(void) {
  return !!(GPIOSCL->DATA & SCL_PIN_MASK);
}

static void reset_bus_state(void) {
  i2c_state = I2C_IDLE;
  bit_count = 0;
  current_byte = 0;
}

/* ========================
   GPIO Interrupt Handler
   ======================== */
// Triggered on rising/falling edges of SDA or SCL
void GPIOA_IRQHandler(void) {
  uint8_t scl = read_SCL();
  uint8_t sda = read_SDA();

  // START condition: SDA falls while SCL high
  if ((scl == 1) && (sda == 0)) {
    reset_bus_state();
    i2c_state = I2C_RECEIVING_ADDR;
		
		GPIOSDA->INTSTATUS = GPIOSDA->INTSTATUS; // reset irq if needed [page 223]
		GPIOSCL->INTSTATUS = GPIOSCL->INTSTATUS; // reset irq if needed [page 223]
    return;
  }

  // STOP condition: SDA rises while SCL high
  if ((scl == 1) && (sda == 1)) {
    reset_bus_state();
		
		GPIOSDA->INTSTATUS = GPIOSDA->INTSTATUS; // reset irq if needed [page 223]
		GPIOSCL->INTSTATUS = GPIOSCL->INTSTATUS; // reset irq if needed [page 223]
    return;
  }
}

/* ========================
   Timer Interrupt Handler
   ======================== */
/** @brief ~200 kHz (every 5 us). Configured in tick.c
 */
void TMR1_IRQHandler(void) {
  static bool scl_prev = 1;
  uint8_t scl = read_SCL();
  uint8_t sda = read_SDA();

  // Rising edge of SCL = sample data
  if ((scl_prev == 0) && (scl == 1)) {
    switch (i2c_state) {
    case I2C_RECEIVING_ADDR:
      current_byte = (current_byte << 1) | (sda & 0x01);
      bit_count++;
      if (bit_count == 8) {
        uint8_t addr = current_byte >> 1;
        rw_flag = current_byte & 0x01;
        if (CHECK_ADDR(addr)) {
					I2C_Current_Address = addr;
					I2C_Current_Page = GET_PAGE(addr);
					I2C_Data_Pointer = I2C_Decode_page_address(I2C_Current_Address, I2C_Current_Page);
          i2c_state = I2C_ACK_PHASE;
        } else {
          reset_bus_state(); // Not our address
        }
        bit_count = 0;
        current_byte = 0;
      }
      break;

    case I2C_RECEIVING_DATA:
      current_byte = (current_byte << 1) | (sda & 0x01);
      bit_count++;
      if (bit_count == 8) {
        // Store received byte
        I2C_Write_data(current_byte, I2C_Current_Address);
        i2c_state = I2C_ACK_PHASE;
        bit_count = 0;
        current_byte = 0;
      }
      break;

    case I2C_SENDING_DATA:
      // Master ACK/NACK after 8 data bits
      if (bit_count == 8) {
        if (sda == 1) {
          // NACK from master -> stop sending
          reset_bus_state();
        } else {
          // ACK -> prepare next byte
          current_byte = I2C_Read_data(I2C_Current_Address);
          bit_count = 0;
          i2c_state = I2C_SENDING_DATA;
        }
      }
      break;

    default:
      break;
    }
  }

  // Falling edge of SCL = drive data if sending
  if ((scl_prev == 1) && (scl == 0)) {
    switch (i2c_state) {
    case I2C_SENDING_DATA:
      if (bit_count < 8) {
        if (current_byte & (0x80 >> bit_count)) {
          release_SDA();
        } else {
          drive_SDA_low();
        }
        bit_count++;
      } else {
        release_SDA(); // release SDA for ACK/NACK bit
      }
      break;

    case I2C_ACK_PHASE:
      if (rw_flag) {
        // Master read -> load first byte to send
        current_byte = I2C_Read_data(I2C_Current_Address);
        bit_count = 0;
        i2c_state = I2C_SENDING_DATA;
      } else {
        // Master write -> send ACK
        drive_SDA_low();
        // Will be released automatically on next SCL falling edge
        release_SDA();
        i2c_state = I2C_RECEIVING_DATA;
      }
      break;

    default:
      break;
    }
  }

  scl_prev = scl;
}

#ifdef __cplusplus
}
#endif // __cplusplus
