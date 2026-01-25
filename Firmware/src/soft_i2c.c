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
  _INT_I2C_IDLE,
  _INT_I2C_START,
  _INT_I2C_SEND_BIT,
  _INT_I2C_RECV_ACK,
  _INT_I2C_RECV_BIT,
  _INT_I2C_SEND_ACK,
  _INT_I2C_STOP
} int_st_t_; // internal i2c state

typedef enum {
  INT_I2C_IDLE,  // idle state
  INT_I2C_START, // start sequence
  INT_I2C_ADDR,  // send or receive address
  INT_I2C_RW,    // read or write bit
  INT_I2C_RACK,  // read ack from data bus
  INT_I2C_WACK,  // write acknolage bit {0 - ACK; 1 - NACK}
  INT_I2C_RDATA, // read data byte from bus
  INT_I2C_WDATA, // write data byte to the bus
  INT_I2C_STOP   // stop sequence
} int_st_t; // internal i2c state

typedef struct
{
  int_st_t       state;

  const uint8_t *tx_buf;
  uint8_t       *rx_buf;
  uint8_t        len;
  uint8_t        index;

  uint8_t        byte;
  int8_t         bit;
  uint8_t        tick;

  uint8_t        busy;
  uint8_t        error;
  uint8_t        ack;

  uint8_t        is_read;
} int_i2c_ctx_t;

typedef struct {
  int_st_t state;
  uint8_t  rw; // 0 - write, !0 - read
  uint8_t  addr;
  uint32_t byte;
  uint8_t  bit; // current bit number of the address or of the byte
  
  const uint8_t* tx_buf; // the buffer for the transmition
  uint32_t   tx_size; // the length of the tx buffer
  uint32_t   tx_id;   // the id of the sended byte in the tx buffer
  uint8_t*   rx_buf;  // the buffer for the receiving
  uint32_t   rx_size; // the size of the availagle receiving buffer (this count of bytes was asked from the slave)
  uint32_t   rx_id;   // the id of the received byte
  
  uint8_t tic; // the number of active substage of the bus
	uint8_t stretch; // 1 - stretched, 0 - normal use

  uint8_t error; // 0 - no error, 1 - ack failed
  uint8_t ack;   // 0 - ACK, 1 - NACK
} int_i2c_t;
  

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

static volatile int_i2c_ctx_t int_i2c_;
static volatile int_i2c_t int_i2c;

static void drive_com_SDA_low(void);

/// @brief To CARL
/// SLAVE  | SCL - A0 | SDA - A1
static void init_com_I2C(void);

/// @brief To MALD and MATA
/// MASTER | SCL - A4 | SDA - A5 
static void init_int_I2C(void);

/// @return 0 - not busy, 1 - busy
static uint8_t is_com_i2c_busy(void);

/// @return 0 - not busy, 1 - busy
static uint8_t is_int_i2c_busy(void);

static void pulldown_com_SCL(void);
static void pulldown_com_SDA(void);
static void pulldown_int_SCL(void);
static void pulldown_int_SDA(void);

static uint8_t read_com_SDA(void);
static uint8_t read_com_SCL(void);
static uint8_t read_int_SDA(void);
// static uint8_t read_int_SCL(void); don't need for master

static void release_com_SCL(void);
static void release_com_SDA(void);
static void release_int_SCL(void);
static void release_int_SDA(void);

static void reset_com_bus_state(void);

static void perform_GPIOA_IRQ_com_event(void);
static void perform_GPIOA_IRQ_int_event(void);

static void perform_TMR_com_event(void);
static void perform_TMR_int_event(void);

static void print_int_state(int state) {
  switch (state) {
  case INT_I2C_IDLE:  printf("IDLE");  break;
  case INT_I2C_START: printf("START"); break;
  case INT_I2C_ADDR:  printf("ADDR");  break;
  case INT_I2C_RW:    printf("RW");    break;
  case INT_I2C_RACK:  printf("RACK");  break;
  case INT_I2C_WACK:  printf("WACK");  break;
  case INT_I2C_RDATA: printf("RDATA"); break;
  case INT_I2C_WDATA: printf("WDATA"); break;
  case INT_I2C_STOP:  printf("STOP");  break;
  default: printf("UNKNOWN(%d)", state); break;
  }
}

void soft_I2C_init(void) {
  //init_com_I2C();
  init_int_I2C();
}

static void drive_com_SDA_low(void) {
  /* open-drain output */
  COM_GPIOSDA->OUTMODE_bit.COM_SDA_PIN = 0x1; // Open Drain [page 212]
  COM_GPIOSDA->OUTENSET_bit.COM_SDA_PIN = 1;  // output enable [page 213]
}

static void init_com_I2C(void) {
  // Configure SDA/SCL pins (A1/A0)
  COM_GPIOSDA->PULLMODE_bit.COM_SDA_PIN = 0x1; // enable pullup [page 51] [page 212]
  COM_GPIOSDA->OUTMODE_bit.COM_SDA_PIN = 0x1 ; // open drain [page 51] [page 212]
  COM_GPIOSDA->OUTENSET_bit.COM_SDA_PIN = 1;   // allow to control port by DATAOUT [page 51] [page 213]
  COM_GPIOSDA->DATA |= COM_SDA_PIN_MASK;       // SDA high
  
  COM_GPIOSDA->DENSET_bit.COM_SDA_PIN = 1; // connect control to the physical port
  
  COM_GPIOSCL->PULLMODE_bit.COM_SCL_PIN = 0x1; // enable pullup [page 51] [page 212]
  COM_GPIOSCL->OUTMODE_bit.COM_SCL_PIN = 0x1;  // open drain [page 51] [page 212]
  COM_GPIOSCL->OUTENSET_bit.COM_SCL_PIN = 1;   // allow to control port by DATAOUT [page 51] [page 213]
  COM_GPIOSCL->DATA |= COM_SCL_PIN_MASK;       // SDA high
  
  COM_GPIOSCL->DENSET_bit.COM_SCL_PIN = 1; // connect control to the physical port
  
  com_i2c_state = I2C_IDLE;
  
  // printf("command: sda:%d, scl:%d\n\r", COM_GPIOSDA->DATA >> 1 & 1, COM_GPIOSCL->DATA >> 0 & 1);
  
  // COM_GPIOSDA->INTENSET_bit.COM_SDA_PIN   = 0x1; // enable SDA interrupt [page 219]
  // COM_GPIOSDA->INTTYPESET_bit.COM_SDA_PIN = 0x1; // by front [page 220]
  // COM_GPIOSDA->INTEDGESET_bit.COM_SDA_PIN = 0x1; // by both raise and fall [page 222]
  
  // COM_GPIOSCL->INTENSET_bit.COM_SCL_PIN   = 0x1; // enable SCL interrupt [page 219]
  // COM_GPIOSCL->INTTYPESET_bit.COM_SCL_PIN = 0x1; // by front [page 220]
  // COM_GPIOSCL->INTPOLSET_bit.COM_SCL_PIN  = 0x1; // by raise [page 221]
}

static void init_int_I2C(void) {
  int sda_pullup = 0x1; // [page 215]
  int scl_pullup = 0x1; // [page 215]
  #if INT_SDA_PIN_MASK != (1 << 5)
  #error "check the new pin and remove or update the define"
  sda_pullup = 0x0; // remove pullup for the testbord the 10k already impletented
  #endif
  #if INT_SCL_PIN_MASK != (1 << 4)
  #error "check the new pin and remove or update the define"
  scl_pullup = 0x0; // remove pullup for the testbord the 10k already impletented
  #endif
  GPIOA->LOCKKEY = 0xADEADBEE; // unlock LOCKSET [page 226]
  GPIOA->LOCKCLR = (1 << 4) | (1 << 5); // unlock A4 and A5 [page 228]
  GPIOA->LOCKKEY = 0x00000000; // lock LOCKSET [page 226]
  GPIOA->ALTFUNCCLR = (1 << 4) | (1 << 5); // clear alternative function for A4 and A5 [page 215]
  
  // now the A4 and A5 are normal reseted pins
  
  // Configure SDA/SCL pins (A5/A4)
  INT_GPIOSDA->PULLMODE_bit.INT_SDA_PIN = sda_pullup; // enable pullup [page 51] [page 212]
  INT_GPIOSDA->OUTMODE_bit.INT_SDA_PIN = 0x1 ; // open drain [page 51] [page 212]
  INT_GPIOSDA->OUTENSET_bit.INT_SDA_PIN = 1;   // allow to control port by DATAOUT [page 51] [page 213]
  INT_GPIOSDA->DATA |= INT_SDA_PIN_MASK;       // SDA high
  
  INT_GPIOSDA->DENSET_bit.INT_SDA_PIN = 1; // connect control to the physical port
  
  INT_GPIOSCL->PULLMODE_bit.INT_SCL_PIN = scl_pullup; // enable pullup [page 51] [page 212]
  INT_GPIOSCL->OUTMODE_bit.INT_SCL_PIN = 0x1;  // open drain [page 51] [page 212]
  INT_GPIOSCL->OUTENSET_bit.INT_SCL_PIN = 1;   // allow to control port by DATAOUT [page 51] [page 213]
  INT_GPIOSCL->DATA |= INT_SCL_PIN_MASK;       // SDA high
  
  INT_GPIOSCL->DENSET_bit.INT_SCL_PIN = 1; // connect control to the physical port
  
  int_i2c.state = INT_I2C_IDLE;
  

  // Enable SDA raise interrupt to detect the orbitration loss.
  // INT_GPIOSDA->INTENSET_bit.INT_SDA_PIN = 1;
  // COM_GPIOSDA->INTTYPESET_bit.INT_SDA_PIN = 0x1; // by front [page 220]
  // COM_GPIOSCL->INTPOLSET_bit.INT_SDA_PIN  = 0x1; // by raise [page 221]
  
  // printf("internal: sda:%d, scl:%d\n\r", INT_GPIOSDA->DATA >> 5 & 1, INT_GPIOSCL->DATA >> 4 & 1);
}

static void pulldown_com_SCL(void) {
  /* input/floating */
  COM_GPIOSCL->DATAOUTCLR = COM_SCL_PIN_MASK; // pull to GND [page 213]
}

static void pulldown_com_SDA(void) {
  /* input/floating */
  COM_GPIOSDA->DATAOUTCLR = COM_SDA_PIN_MASK; // pull to GND [page 213]
}

static void pulldown_int_SCL(void) {
  //printf("scl0\n\r");
  INT_GPIOSCL->DATAOUTCLR = INT_SCL_PIN_MASK; // pull to GND
}

static void pulldown_int_SDA(void) {
  //printf("sda0\n\r");
  INT_GPIOSDA->DATAOUTCLR = INT_SDA_PIN_MASK; // pull to GND
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

static uint8_t read_int_SCL(void) {
  return !!(INT_GPIOSCL->DATA & INT_SCL_PIN_MASK);
}

static void release_com_SDA(void) {
  /* input/floating */
  COM_GPIOSDA->DATAOUTSET_bit.COM_SDA_PIN = 1; // Z-state [page 213]
}

static void release_int_SCL(void) {
  //printf("scl1\n\r");
  INT_GPIOSCL->DATAOUTSET_bit.INT_SCL_PIN = 1; // Z-state
}

static void release_int_SDA(void) {
  //printf("sda1\n\r");
  INT_GPIOSDA->DATAOUTSET_bit.INT_SDA_PIN = 1; // Z-state
}

// don't need for master
// static uint8_t read_int_SCL(void) {
//   return !!(INT_GPIOSCL->DATA & INT_SCL_PIN_MASK);
// }

static uint8_t is_com_i2c_busy(void) {
  return 0;
  // return int_i2c.state != I2C_IDLE;
}

static uint8_t is_int_i2c_busy(void) {
  return int_i2c.state != INT_I2C_IDLE;
}

static void reset_com_bus_state(void) {
  com_i2c_state = I2C_IDLE;
  com_bit_count = 0;
  com_current_byte = 0;
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
      //reset_int_bus_state();
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

static void perform_int_tic0(void) {
  switch (int_i2c.state) {
    case INT_I2C_START:
      pulldown_int_SDA();      
      break;
    case INT_I2C_ADDR:
      (int_i2c.addr >> int_i2c.bit) & 1 ? release_int_SDA() : pulldown_int_SDA();
      break;
    case INT_I2C_RW:
      int_i2c.rw ? release_int_SDA() : pulldown_int_SDA();
      break;
    case INT_I2C_RACK:
      release_int_SDA(); // release sda for ack and wait for an ack
      break;
    case INT_I2C_WACK:
      pulldown_int_SDA(); // send ack
      break;
    case INT_I2C_RDATA:
      release_int_SDA();
      break;
    case INT_I2C_WDATA:
      ((int_i2c.byte >> int_i2c.bit) & 1) ? release_int_SDA() : pulldown_int_SDA();
      break;
    default:
      break;
  }
}

static void perform_int_tic1(void) {
  if (int_i2c.state != INT_I2C_IDLE && int_i2c.state != INT_I2C_START) {
    release_int_SCL();
  }
}

static void perform_int_tic2(void) {
	if (!read_int_SCL()) {
		int_i2c.stretch = 1;
		return;
	}
	
  switch (int_i2c.state) {
    case INT_I2C_RACK:
      int_i2c.ack = read_int_SDA();
      break;
    case INT_I2C_RDATA:
      int_i2c.byte |= read_int_SDA() << int_i2c.bit;
      break;
    default:
      break;
  }
}

static void perform_int_tic3(void) {
	if (int_i2c.stretch) {
		int_i2c.stretch = 0;
		return; // hold the state
	}

  if (int_i2c.state != INT_I2C_IDLE && int_i2c.state != INT_I2C_STOP) {
    pulldown_int_SCL();
  }
	else if (int_i2c.state == INT_I2C_STOP) {
	  release_int_SDA(); // stop, set sda to high state
	}
  
  switch (int_i2c.state) {
    case INT_I2C_START:
      int_i2c.bit = 6;
      int_i2c.state = INT_I2C_ADDR;
      break;
    
    case INT_I2C_ADDR:
      if (int_i2c.bit > 0) {
        int_i2c.bit--;
        break;
      }
      int_i2c.state = INT_I2C_RW;
      break;
      
    case INT_I2C_RW:
      int_i2c.state = INT_I2C_RACK;
      break;
    
    case INT_I2C_RACK:
      if (0 && int_i2c.ack) {
        int_i2c.error = 1;
        int_i2c.state = INT_I2C_STOP;
        break;
      }
      if (int_i2c.tx_id >= int_i2c.tx_size) { // nothing to transmit
        if (int_i2c.rx_id >= int_i2c.rx_size) { // not waiting for bytes
          int_i2c.state = INT_I2C_STOP;
          break;
        }
        int_i2c.bit = 7;
        int_i2c.byte = 0;
        int_i2c.state = INT_I2C_RDATA;
        break;
      }
      int_i2c.bit = 7;
      int_i2c.byte = int_i2c.tx_buf[int_i2c.tx_id];
      int_i2c.state = INT_I2C_WDATA;
      break;
      
    case INT_I2C_WACK:
      if (int_i2c.rx_id >= int_i2c.rx_size) { // not waiting for bytes
        int_i2c.state = INT_I2C_STOP;
        break;
      }
      int_i2c.bit = 7;
      int_i2c.byte = 0;
      int_i2c.state = INT_I2C_RDATA;
      break;
      
    case INT_I2C_RDATA:
      if (int_i2c.bit > 0) {
        int_i2c.bit--;
        break;
      }
      int_i2c.rx_buf[int_i2c.rx_id] = int_i2c.byte;
      int_i2c.rx_id++;
      int_i2c.state = INT_I2C_WACK;
      break;
      
    case INT_I2C_WDATA:
      if (int_i2c.bit > 0) {
        int_i2c.bit--;
        break;
      }
      int_i2c.tx_id++;
      int_i2c.state = INT_I2C_RACK;
      break;
      
    case INT_I2C_STOP:
      int_i2c.state = INT_I2C_IDLE;
      break;
    
    default:
      break;
  }
}

static void perform_TMR_int_event(void) {
  if (int_i2c.state == INT_I2C_IDLE) {
    return;
  }

  //printf("tic:%d\n\r", int_i2c.tic);
  switch (int_i2c.tic) {
  case 0:
    perform_int_tic0();
    int_i2c.tic++;
    break;
  case 1:
    perform_int_tic1();
    int_i2c.tic++;
    break;
  case 2:
    perform_int_tic2();
    int_i2c.tic++;
    break;
  case 3:
    perform_int_tic3();
    int_i2c.tic = 0;
    break;
  default:
    int_i2c.tic = 0;
    break;
  }
}

/** @brief ~400 kHz (every 2.5 us). Configured in tick.c
 */
void TMR1_IRQHandler(void) {
  //perform_TMR_com_event();
  perform_TMR_int_event();
  
  TMR1->INTSTATUS = TMR_INTSTATUS_INT_Msk;
}

// ==============================================================================
// INTERNAL I2C API
// ==============================================================================

void int_I2C_start_read(uint8_t addr, const uint8_t* wr_data, uint32_t wr_data_size, uint8_t *buffer, uint32_t size) {
  if (is_int_i2c_busy()) return;

  int_i2c.addr = addr;
  int_i2c.rw = 1; // read
    
  int_i2c.tx_buf = wr_data;
  int_i2c.tx_size = wr_data_size;
  int_i2c.tx_id = 0;

  int_i2c.rx_buf = buffer;
  int_i2c.rx_size = size;
  int_i2c.tx_id = 0;

  int_i2c.ack = 1; // no ack
  int_i2c.error = 0; // no error
	int_i2c.stretch = 0; // normal mode
  
  int_i2c.state = INT_I2C_START;
}

void int_I2C_start_write(uint8_t addr, const uint8_t *data, uint8_t len) {
  if (is_int_i2c_busy()) return;

  int_i2c.addr = addr;
  int_i2c.rw = 0; // write
    
  int_i2c.tx_buf = data;
  int_i2c.tx_size = len;
  int_i2c.tx_id = 0;

  int_i2c.rx_buf = 0x0;
  int_i2c.rx_size = 0;
  int_i2c.tx_id = 0;

  int_i2c.ack = 1; // no ack
  int_i2c.error = 0; // no error
	int_i2c.stretch = 0; // normal mode
  
  int_i2c.state = INT_I2C_START;
}

uint8_t int_I2C_read_complete(void) {
    if (is_int_i2c_busy()) {
        return 2; // BUSY
    }
    
    // check read after write operation
    if (!int_i2c.rw) {
      return 1; // ERROR
    }

    /* If not busy, but no read was in progress return ERROR */
    if (int_i2c.error) {
        return 1; // ERROR
    }

    return 0; // SUCCESS
}

uint8_t int_I2C_write_complete(void) {
    if (is_int_i2c_busy()) {
        return 2; // BUSY
    }
    
    // check wtire after read operation
    if (int_i2c.rw) {
      return 1; // ERROR
    }

    /* If not busy, but no write was in progress return ERROR */
    if (int_i2c.error) {
        return 1; // ERROR
    }

    return 0; // SUCCESS
}

uint8_t int_I2C_read(uint8_t addr, uint8_t *buffer, uint8_t len) {
  int_I2C_start_read(addr, 0x0, 0, buffer, len);
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
