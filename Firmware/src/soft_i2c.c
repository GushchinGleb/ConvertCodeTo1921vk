#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/soft_i2c.h"

#include <stdint.h>
#include <stdbool.h>

#include "K1921VK035.h"

#define CHECK_ADDR(addr) ((addr & 0xFC) == 0xA0) // addr=[0xA0;0xA3]
#define GET_PAGE(addr)   (addr & 0xFE) //  addr=[0xA0;0xA3] -> page={0xA0;0xA2}

typedef enum {
  I2C_IDLE,
  I2C_RECEIVING_ADDR,
  I2C_RECEIVING_DATA,
  I2C_SENDING_DATA,
  I2C_ACK_PHASE,
  I2C_STOP
} i2c_st_t; // com i2c state

typedef enum {
  INT_I2C_IDLE,
  INT_I2C_START,
  INT_I2C_SEND_BYTE,
  INT_I2C_RECV_ACK,
  INT_I2C_RECV_BYTE,
  INT_I2C_SEND_ACK,
  INT_I2C_STOP
} int_st_t; // internal i2c state

struct int_i2c_state {
  const uint8_t *tx;
  uint8_t *rx;
  uint8_t tx_len;
  uint8_t rx_len;
  uint8_t tx_index;
  uint8_t rx_index;
  uint8_t current_byte;
  uint8_t bit_index;
  uint8_t scl_state; // 0 = SCL low, 1 = high
  int_st_t state;
  uint8_t busy;
};

extern uint8_t* I2C_Data_Pointer; // from soft_i2c_api.c for communication with the external computer

static volatile i2c_st_t com_i2c_state = I2C_IDLE;
static volatile uint8_t  com_bit_count = 0;
static volatile uint8_t  com_current_byte = 0;
static volatile bool     com_rw_flag = false; // 0 = slave write, 1 = slave read

/*
 The controller accept all incomming data for any destination address.
 It saves the addres for future use in I2C_Write_data or I2C_Read_data API funtions.
*/
static uint8_t com_I2C_Current_Address = 0; // for communication (COMM)
/*
 The number of the page. 0xA0 is for A0 page structure, same for 0xA2.
*/
static uint8_t com_I2C_Current_Page = 0;

static volatile struct int_i2c_state int_i2c;

static void drive_com_SDA_low(void);
static void drive_int_SDA_low(void);

/// @brief To CARL
/// SLAVE  | SCL - A0 | SDA - A1
static void init_com_I2C(void);

/// @brief To MALD and MATA
/// MASTER | SCL - A4 | SDA - A5 
static void init_int_I2C(void);

static uint8_t read_com_SDA(void);
static uint8_t read_com_SCL(void);
static uint8_t read_int_SDA(void);
// static uint8_t read_int_SCL(void); don't need for master

static void release_com_SDA(void);
static void release_int_SDA(void);

static void reset_com_bus_state(void);
static void reset_int_bus_state(void);

static void perform_GPIOA_IRQ_com_event(void);
static void perform_GPIOA_IRQ_int_event(void);

static void perform_TMR_com_event(void);
static void perform_TMR_int_event(void);

void soft_I2C_init(void) {
  init_com_I2C();
  init_int_I2C();
}

static void drive_com_SDA_low(void) {
  /* open-drain output */
  COM_GPIOSDA->OUTMODE_bit.COM_SDA_PIN = 0x1; // Open Drain [page 212]
  COM_GPIOSDA->OUTENSET_bit.COM_SDA_PIN = 1;  // output enable [page 213]
}

static void drive_int_SDA_low(void) {
  INT_GPIOSDA->OUTMODE_bit.INT_SDA_PIN = 0x1; // open drain
  INT_GPIOSDA->OUTENSET_bit.INT_SDA_PIN = 1;  // enable output
}

static void init_com_I2C(void) {
  COM_GPIOSDA->DRIVEMODE_bit.COM_SDA_PIN = 0x2; // 10 - low power, high speed [213]
  COM_GPIOSCL->DRIVEMODE_bit.COM_SCL_PIN = 0x2; // 10 - low power, high speed [213]
  
  COM_GPIOSDA->INTENSET_bit.COM_SDA_PIN   = 0x1; // enable SDA interrupt [page 219]
  COM_GPIOSDA->INTTYPESET_bit.COM_SDA_PIN = 0x1; // by front [page 220]
  COM_GPIOSDA->INTEDGESET_bit.COM_SDA_PIN = 0x1; // by both raise and fall [page 222]
  
  COM_GPIOSCL->INTENSET_bit.COM_SCL_PIN   = 0x1; // enable SCL interrupt [page 219]
  COM_GPIOSCL->INTTYPESET_bit.COM_SCL_PIN = 0x1; // by front [page 220]
  COM_GPIOSCL->INTPOLSET_bit.COM_SCL_PIN  = 0x1; // by raise [page 221]
}

static void init_int_I2C(void) {
  // Configure SDA/SCL pins (A5/A4)
  INT_GPIOSDA->DRIVEMODE_bit.INT_SDA_PIN = 0x2; // low power + high speed
  INT_GPIOSCL->DRIVEMODE_bit.INT_SCL_PIN = 0x2;
  
  release_int_SDA();   // SDA high
  INT_GPIOSCL->OUTENSET_bit.INT_SCL_PIN = 1;
  INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK;  // SCL high
  
  int_i2c.state = INT_I2C_IDLE;
  int_i2c.busy  = 0;

	// Enable SDA raise interrupt to detect the orbitration loss.
  INT_GPIOSDA->INTENSET_bit.INT_SDA_PIN = 1;
  COM_GPIOSDA->INTTYPESET_bit.INT_SDA_PIN = 0x1; // by front [page 220]
  COM_GPIOSCL->INTPOLSET_bit.INT_SDA_PIN  = 0x1; // by raise [page 221]
}

static void release_com_SDA(void) {
  /* input/floating */
  COM_GPIOSDA->OUTENSET_bit.COM_SDA_PIN = 0; // output disable, Z-state [page 213]
  COM_GPIOSDA->DENSET_bit.COM_SDA_PIN = 0x0; // push pull [page 212]
  COM_GPIOSDA->INMODE_bit.COM_SDA_PIN = 0x0; // Schmit trigger [page 51], [page 9], [page 211]
}

static void release_int_SDA(void) {
  INT_GPIOSDA->OUTENSET_bit.INT_SDA_PIN = 0; // disable output
  INT_GPIOSDA->DENSET_bit.INT_SDA_PIN = 0x0; // push-pull disabled
  INT_GPIOSDA->INMODE_bit.INT_SDA_PIN = 0x0; // input, schmitt
}

static uint8_t read_com_SDA(void) {
  return !!(COM_GPIOSDA->DATA & COM_SDA_PIN_MASK);
}

static uint8_t read_com_SCL(void) {
  return !!(COM_GPIOSCL->DATA & COM_SCL_PIN_MASK);
}

static uint8_t read_int_SDA(void) {
  return !!(INT_GPIOSDA->DATA & INT_SDA_PIN_MASK);
}

// don't need for master
// static uint8_t read_int_SCL(void) {
//   return !!(INT_GPIOSCL->DATA & INT_SCL_PIN_MASK);
// }

static void reset_com_bus_state(void) {
  com_i2c_state = I2C_IDLE;
  com_bit_count = 0;
  com_current_byte = 0;
}

static void reset_int_bus_state(void) {
  int_i2c.state = INT_I2C_IDLE;
  int_i2c.busy = 0;
  release_int_SDA();
  INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK;
}

/* ========================
   GPIO Interrupt Handler
   ======================== */
// Triggered on rising/falling edges of SDA or SCL
void GPIOA_IRQHandler(void) {
  perform_GPIOA_IRQ_com_event();
  perform_GPIOA_IRQ_int_event();
}

static void perform_GPIOA_IRQ_com_event(void) {
  uint8_t scl = read_com_SCL();
  uint8_t sda = read_com_SDA();

  // START condition: SDA falls while SCL high
  if ((scl == 1) && (sda == 0)) {
    reset_com_bus_state();
    com_i2c_state = I2C_RECEIVING_ADDR;
    
    COM_GPIOSDA->INTSTATUS = COM_GPIOSDA->INTSTATUS; // reset irq if needed [page 223]
    COM_GPIOSCL->INTSTATUS = COM_GPIOSCL->INTSTATUS; // reset irq if needed [page 223]
    return;
  }

  // STOP condition: SDA rises while SCL high
  if ((scl == 1) && (sda == 1)) {
    reset_com_bus_state();
    
    COM_GPIOSDA->INTSTATUS = COM_GPIOSDA->INTSTATUS; // reset irq if needed [page 223]
    COM_GPIOSCL->INTSTATUS = COM_GPIOSCL->INTSTATUS; // reset irq if needed [page 223]
    return;
  }
}

  // Ddetect arbitration loss
static void perform_GPIOA_IRQ_int_event(void) {

  // If master drives SDA low but line is high, some other master wins.
  if (int_i2c.state != INT_I2C_IDLE &&
      INT_GPIOSDA->OUTENSET_bit.INT_SDA_PIN == 1
  ) {
      reset_int_bus_state();
  }

  INT_GPIOSDA->INTSTATUS = INT_GPIOSDA->INTSTATUS; // reset irq if needed [page 223]
  INT_GPIOSCL->INTSTATUS = INT_GPIOSCL->INTSTATUS; // reset irq if needed [page 223]
}

static void perform_TMR_com_event(void) {
  static bool scl_prev = 1;
  const uint8_t scl = read_com_SCL();
  const uint8_t sda = read_com_SDA();

  // Rising edge of SCL = sample data
  if ((scl_prev == 0) && (scl == 1)) {
    switch (com_i2c_state) {
    case I2C_RECEIVING_ADDR:
      com_current_byte = (com_current_byte << 1) | (sda & 0x01);
      com_bit_count++;
      if (com_bit_count == 8) {
        const uint8_t addr = com_current_byte >> 1;
        com_rw_flag = com_current_byte & 0x01;
        if (CHECK_ADDR(addr)) {
          com_I2C_Current_Address = addr;
          com_I2C_Current_Page = GET_PAGE(addr);
          I2C_Data_Pointer = com_I2C_Decode_page_address(com_I2C_Current_Address, com_I2C_Current_Page);
          com_i2c_state = I2C_ACK_PHASE;
        } else {
          reset_com_bus_state(); // Not our address
        }
        com_bit_count = 0;
        com_current_byte = 0;
      }
      break;

    case I2C_RECEIVING_DATA:
      com_current_byte = (com_current_byte << 1) | (sda & 0x01);
      com_bit_count++;
      if (com_bit_count == 8) {
        // Store received byte
        com_I2C_Write_data(com_current_byte, com_I2C_Current_Address);
        com_i2c_state = I2C_ACK_PHASE;
        com_bit_count = 0;
        com_current_byte = 0;
      }
      break;

    case I2C_SENDING_DATA:
      // Master ACK/NACK after 8 data bits
      if (com_bit_count == 8) {
        if (sda == 1) {
          // NACK from master -> stop sending
          reset_com_bus_state();
        } else {
          // ACK -> prepare next byte
          com_current_byte = com_I2C_Read_data(com_I2C_Current_Address);
          com_bit_count = 0;
          com_i2c_state = I2C_SENDING_DATA;
        }
      }
      break;

    default:
      break;
    }
  }

  // Falling edge of SCL = drive data if sending
  if ((scl_prev == 1) && (scl == 0)) {
    switch (com_i2c_state) {
    case I2C_SENDING_DATA:
      if (com_bit_count < 8) {
        if (com_current_byte & (0x80 >> com_bit_count)) {
          release_com_SDA();
        } else {
          drive_com_SDA_low();
        }
        com_bit_count++;
      } else {
        release_com_SDA(); // release SDA for ACK/NACK bit
      }
      break;

    case I2C_ACK_PHASE:
      if (com_rw_flag) {
        // Master read -> load first byte to send
        com_current_byte = com_I2C_Read_data(com_I2C_Current_Address);
        com_bit_count = 0;
        com_i2c_state = I2C_SENDING_DATA;
      } else {
        // Master write -> send ACK
        drive_com_SDA_low();
        // Will be released automatically on next SCL falling edge
        release_com_SDA();
        com_i2c_state = I2C_RECEIVING_DATA;
      }
      break;

    default:
      break;
    }
  }

  scl_prev = scl;
}

static void perform_TMR_int_event(void) {
	static int prev_state = 0xFF;
	if (prev_state != int_i2c.state) {
		printf("int: %d -> %d\n\r", prev_state, int_i2c.state);
		prev_state = int_i2c.state;
	}
  switch (int_i2c.state) {
  case INT_I2C_IDLE:
      return;

  /* ---------------- START CONDITION ---------------- */
  case INT_I2C_START:
      release_int_SDA();
      INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK; // SCL high
      // SDA high ? low while SCL high
      if (read_int_SDA() == 1) {
          drive_int_SDA_low();
          int_i2c.state = INT_I2C_SEND_BYTE;
      }
      break;

  /* ---------------- SEND 8 BITS ---------------- */
  case INT_I2C_SEND_BYTE:
      // SCL low ? drive bit
      INT_GPIOSCL->DATA &= ~INT_SCL_PIN_MASK;

      if (int_i2c.current_byte & (1 << int_i2c.bit_index))
          release_int_SDA();
      else
          drive_int_SDA_low();

      // SCL high ? master must let slave sample
      INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK;

      if (int_i2c.bit_index == 0) {
          int_i2c.state = INT_I2C_RECV_ACK;
          release_int_SDA();     // SDA released for ACK
      } else {
          int_i2c.bit_index--;
      }
      break;

  /* ---------------- EXPECT ACK ---------------- */
  case INT_I2C_RECV_ACK:
      INT_GPIOSCL->DATA &= ~INT_SCL_PIN_MASK;
      INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK; // rising

      if (read_int_SDA() != 0) {
          // NACK ? STOP immediately
          int_i2c.state = INT_I2C_STOP;
          break;
      }

      // ACK OK:
      if (int_i2c.tx_index < int_i2c.tx_len) {
          int_i2c.current_byte = int_i2c.tx[int_i2c.tx_index++];
          int_i2c.bit_index = 7;
          int_i2c.state = INT_I2C_SEND_BYTE;
      }
      else if (int_i2c.rx_len > 0) {
          int_i2c.bit_index = 7;
          int_i2c.current_byte = 0;
          int_i2c.state = INT_I2C_RECV_BYTE;
      }
      else {
          int_i2c.state = INT_I2C_STOP;
      }
      break;

  /* ---------------- RECEIVE 8 BITS ---------------- */
  case INT_I2C_RECV_BYTE:
      INT_GPIOSCL->DATA &= ~INT_SCL_PIN_MASK;
      release_int_SDA(); // input mode
      INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK; // rising

      int_i2c.current_byte =
          (int_i2c.current_byte << 1) | read_int_SDA();

      if (int_i2c.bit_index == 0) {
          int_i2c.rx[int_i2c.rx_index++] = int_i2c.current_byte;
          int_i2c.state = INT_I2C_SEND_ACK;
      } else {
          int_i2c.bit_index--;
      }
      break;

  /* ---------------- SEND ACK/NACK ---------------- */
  case INT_I2C_SEND_ACK:
      INT_GPIOSCL->DATA &= ~INT_SCL_PIN_MASK;

      if (int_i2c.rx_index < int_i2c.rx_len)
          drive_int_SDA_low();   // ACK
      else
          release_int_SDA();     // NACK

      INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK;

      release_int_SDA();
      if (int_i2c.rx_index < int_i2c.rx_len) {
          int_i2c.bit_index = 7;
          int_i2c.current_byte = 0;
          int_i2c.state = INT_I2C_RECV_BYTE;
      } else {
          int_i2c.state = INT_I2C_STOP;
      }
      break;

  /* ---------------- STOP CONDITION ---------------- */
  case INT_I2C_STOP:
      INT_GPIOSCL->DATA &= ~INT_SCL_PIN_MASK;
      drive_int_SDA_low();
      INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK;
      release_int_SDA(); // SDA low ? high while SCL high
      reset_int_bus_state();
      break;
  }
}

/** @brief ~200 kHz (every 5 us). Configured in tick.c
 */
void TMR1_IRQHandler(void) {
  perform_TMR_com_event();
  perform_TMR_int_event();
	
	TMR1->INTSTATUS = TMR_INTSTATUS_INT_Msk;
}

// ==============================================================================
// INTERNAL I2C API
// ==============================================================================

void int_I2C_start_read(uint8_t addr, uint8_t *buffer, uint8_t len) {
    if (int_i2c.busy) {
			return;
		}

    int_i2c.rx = buffer;
    int_i2c.rx_len = len;
    int_i2c.rx_index = 0;
    int_i2c.tx_len = 0;
    int_i2c.busy = 1;

    int_i2c.current_byte = (addr << 1) | 1; // R
    int_i2c.bit_index = 7;

    int_i2c.state = INT_I2C_START;
}

void int_I2C_start_write(uint8_t addr, const uint8_t *data, uint8_t len) {
    if (int_i2c.busy) {
      return;
    }

    int_i2c.tx = data;
    int_i2c.tx_len = len;
    int_i2c.tx_index = 0;
    int_i2c.rx = (void*)0x0;
    int_i2c.rx_len = 0;
    int_i2c.busy = 1;

    // Load first byte (address << 1) | W
    int_i2c.current_byte = (addr << 1) | 0;
    int_i2c.bit_index = 7;

    int_i2c.state = INT_I2C_START;
}

uint8_t int_I2C_read_complete(void) {
    if (int_i2c.busy) {
        return 2; // BUSY
		}

    /* If not busy, but no read was in progress return ERROR */
    if (int_i2c.rx_len == 0) {
        return 1; // ERROR
		}

    return 0; // SUCCESS
}

uint8_t int_I2C_write_complete(void) {
    if (int_i2c.busy) {
        return 2; // BUSY
		}

    /* If not busy, but no write was in progress return ERROR */
    if (int_i2c.tx_len == 0) {
        return 1; // ERROR
		}

    return 0; // SUCCESS
}

uint8_t int_I2C_read(uint8_t addr, uint8_t *buffer, uint8_t len) {
	int_I2C_start_read(addr, buffer, len);
	uint8_t status = 0;
	do {
		status = int_I2C_read_complete();
	} while (status == 2); // BUSY
	
	return status == 0 ? 0 : 1;
}

uint8_t int_I2C_write(uint8_t addr, const uint8_t *data, uint8_t len) {
	int_I2C_start_write(addr, data, len);
	uint8_t status = 0;
	
	volatile uint32_t tiks = SystemCoreClock / 4;
	
	do {
		status = int_I2C_write_complete();
	} while (status == 2 && tiks--); // BUSY
	
	if (status == 2) {
		printf("Timeout\n\r");
	}
	
	return status == 0 ? 0 : 1;
}

#ifdef __cplusplus
}
#endif // __cplusplus
