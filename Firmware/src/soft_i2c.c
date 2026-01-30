#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/soft_i2c.h"

#include <stdint.h>
#include <stdbool.h>

#include "K1921VK035.h"

#define CHECK_ADDR(addr) ((addr & 0xFC) == 0xA0) // addr=[0xA0;0xA3]
#define GET_PAGE(addr)   (addr & 0xFE) //  addr=[0xA0;0xA3] -> page={0xA0;0xA2}

#define CHECK_COM_I2C
#ifdef CHECK_COM_I2C
uint8_t i2c_debug_buff[16] = "";
#endif // CHECK_COM_I2C

typedef enum {
  COM_I2C_IDLE,
  COM_I2C_START,
  COM_I2C_ADDR,  // sample address
  COM_I2C_RW,    // sample mode: 0 - read from master, 1 - write to master
  COM_I2C_RACK,  // read ack
  COM_I2C_WACK,  // write ack
  COM_I2C_RADDR, // read the local address of the data in the page
  COM_I2C_RDATA, // read data from master
  COM_I2C_WDATA, // wtite data to the master
  COM_I2C_STOP
} com_st_t;

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

typedef struct {
  uint8_t  sda; // state of the sda: 0 - pulldown, !0 - release
  uint8_t  scl; // state of the scl: 0 - pulldown, !0 - release

  com_st_t state;
  uint8_t  rw; // 0 - read from master, !0 - write to master
  uint8_t  addr;
  uint32_t byte;
  uint8_t  bit; // current bit number of the address or of the byte
  
  uint8_t    p_id;    // the index of the page {0xA0; 0xA1}
  uint8_t    l_addr;  // the local address of data in the selected page
  uint8_t    f_raddr;  // flag 0 - perform read / write operation; 1 - read the local address 

  uint8_t tic; // the number of active substage of the bus
  uint8_t stretch; // 1 - stretched, 0 - normal use

  uint8_t error; // 0 - no error, 1 - ack failed
  uint8_t ack;   // 0 - ACK, 1 - NACK
} com_i2c_t;

typedef struct {
  int_st_t state;
  uint8_t  rw; // 0 - write, !0 - read
  uint8_t  addr;
  uint32_t byte;
  uint8_t  bit; // current bit number of the address or of the byte
  
  uint8_t    p_id;    // the index of the page {0x50 (A0); 0x51 (A2)}
  
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

static volatile com_i2c_t com_i2c; // slave | external computer
static volatile int_i2c_t int_i2c; // master | internal communitation

static void com_i2c_addres_clear(void);
static void com_i2c_addres_set(void);

/// @brief To CARL
/// SLAVE  | SCL - A0 | SDA - A1
static void init_com_I2C(void);

/// @brief To MALD and MATA
/// MASTER | SCL - A4 | SDA - A5 
static void init_int_I2C(void);

/// @return 0 - not busy, 1 - busy
//static uint8_t is_com_i2c_busy(void);

/// @return 0 - not busy, 1 - busy
static uint8_t is_int_i2c_busy(void);

//static void pulldown_com_SCL(void); // set stretch
static void pulldown_com_SDA(void);
static void pulldown_int_SCL(void);
static void pulldown_int_SDA(void);

static uint8_t read_com_SDA(void);
static uint8_t read_com_SCL(void);
static uint8_t read_int_SDA(void);
// static uint8_t read_int_SCL(void); don't need for master

// static void release_com_SCL(void); // release stretch
static void release_com_SDA(void);
static void release_int_SCL(void);
static void release_int_SDA(void);

static void perform_GPIOA_IRQ_com_event(void);
// static void perform_GPIOA_IRQ_int_event(void);

static void perform_SCL_fall_action(void); // write data to the master
static void perform_SCL_raise_action(void); // read data from the master
static void perform_SDA_START(void); // sda fall while the scl is HIGH
static void perform_SDA_STOP(void); // sda raise while the scl is LOW

static void perform_TMR_int_event(void);

static void print_com_state(int state) {
  switch (state) {
  case COM_I2C_IDLE:  printf("I");  break;
  case COM_I2C_START: printf("S");  break;
  case COM_I2C_ADDR:  printf("A");  break;
  case COM_I2C_RADDR: printf("RR"); break;
  case COM_I2C_RW:    printf("RW"); break;
  case COM_I2C_RACK:  printf("RA"); break;
  case COM_I2C_WACK:  printf("WA"); break;
  case COM_I2C_RDATA: printf("RD"); break;
  case COM_I2C_WDATA: printf("WD"); break;
  case COM_I2C_STOP:  printf("ST"); break;
  default: printf("U(%d)", state); break;
  }
}

static void print_int_state(int state) {
  switch (state) {
  case INT_I2C_IDLE:  printf("I");  break;
  case INT_I2C_START: printf("S"); break;
  case INT_I2C_ADDR:  printf("A");  break;
  case INT_I2C_RW:    printf("RW");    break;
  case INT_I2C_RACK:  printf("RA");  break;
  case INT_I2C_WACK:  printf("WA");  break;
  case INT_I2C_RDATA: printf("RD"); break;
  case INT_I2C_WDATA: printf("WD"); break;
  case INT_I2C_STOP:  printf("ST");  break;
  default: printf("U(%d)", state); break;
  }
}

void soft_I2C_init(void) {
  init_com_I2C();
  init_int_I2C();
}

static void com_i2c_addres_clear(void) {
  I2C_Data_Pointer = 0x0;
}

static void com_i2c_addres_set(void) {
  I2C_Data_Pointer = com_I2C_Decode_page_address(com_i2c.l_addr, com_i2c.p_id);
}

static void init_com_I2C(void) {
  // 10K resistor already implemented
  // set both to 0x1 if the wires not pulled to the 3V3
  int sda_pullup = 0x0; // [page 215]
  int scl_pullup = 0x0; // [page 215]
  
  // Configure SDA/SCL pins (A1/A0)
  COM_GPIOSDA->PULLMODE_bit.COM_SDA_PIN = sda_pullup; // enable pullup [page 51] [page 212]
  COM_GPIOSDA->OUTMODE_bit.COM_SDA_PIN = 0x1 ; // open drain [page 51] [page 212]
  COM_GPIOSDA->OUTENSET_bit.COM_SDA_PIN = 1;   // allow to control port by DATAOUT [page 51] [page 213]
  COM_GPIOSDA->DATA |= COM_SDA_PIN_MASK;       // SDA high
  
  COM_GPIOSDA->DENSET_bit.COM_SDA_PIN = 1; // connect control to the physical port
  
  COM_GPIOSCL->PULLMODE_bit.COM_SCL_PIN = scl_pullup; // enable pullup [page 51] [page 212]
  COM_GPIOSCL->OUTMODE_bit.COM_SCL_PIN = 0x1;  // open drain [page 51] [page 212]
  COM_GPIOSCL->OUTENSET_bit.COM_SCL_PIN = 1;   // allow to control port by DATAOUT [page 51] [page 213]
  COM_GPIOSCL->DATA |= COM_SCL_PIN_MASK;       // SDA high
  
  COM_GPIOSCL->DENSET_bit.COM_SCL_PIN = 1; // connect control to the physical port
  
  com_i2c.state = COM_I2C_IDLE;
  com_i2c.sda = read_com_SDA();
  com_i2c.scl = read_com_SCL();
  
  // pospond sda to remove false position STOP and START sequences
  COM_GPIOSDA->SYNCSET_bit.COM_SDA_PIN = 1;  // enable resenhronization [page 215]
  COM_GPIOSDA->QUALSET_bit.COM_SDA_PIN = 1;  // enable input filter [page 216]
  COM_GPIOSDA->QUALMODESET_bit.COM_SDA_PIN = 1; // enable 6 counts in row [page 217]
  
  //COM_GPIOSDA->INTTYPECLR = COM_SDA_PIN_MASK; // by level (default)
  COM_GPIOSDA->INTPOLSET = com_i2c.sda ? 0 : COM_SDA_PIN_MASK; // set to oposit pin state
  
  //COM_GPIOSDA->INTTYPECLR = COM_SCL_PIN_MASK; // by level (default)
  COM_GPIOSDA->INTPOLSET = com_i2c.scl ? 0 : COM_SCL_PIN_MASK; // set to oposit pin state
  
  #if defined(COM_SDA_GPIOB) || defined(COM_SCL_GPIOB) || defined(INT_SDA_GPIOB) || defined(INT_SCL_GPIOB)
  #error "Reconfigure the interrupt setup and logic of the handlers. Then update to check abowe."
  #endif
  NVIC_SetPriority(GPIOA_IRQn, (1UL << __NVIC_PRIO_BITS) + 2UL); // I2C master pins. High priority.
  GPIOA->INTSTATUS = GPIOA->INTSTATUS;
  NVIC_EnableIRQ(GPIOA_IRQn);
  
  GPIOA->INTENSET = COM_SCL_PIN_MASK | COM_SDA_PIN_MASK; // enable SCL and SDA interrupts [page 219]
  
  // printf("command: sda:%d, scl:%d\n\r", COM_GPIOSDA->DATA >> 1 & 1, COM_GPIOSCL->DATA >> 0 & 1);
}

static void init_int_I2C(void) {
  // Set both to 0x0
  // if the wires is pulled to the 3V3
  int sda_pullup = 0x1; // [page 215]
  int scl_pullup = 0x1; // [page 215]
  #if INT_SDA_PIN_MASK != (1 << 5)
  #error "check the new pin and remove or update the define"
  #endif
  #if INT_SCL_PIN_MASK != (1 << 4)
  #error "check the new pin and remove or update the define"
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
  
  // printf("internal: sda:%d, scl:%d\n\r", INT_GPIOSDA->DATA >> 5 & 1, INT_GPIOSCL->DATA >> 4 & 1);
}

#if 0
static void pulldown_com_SCL(void) {
  /* input/floating */
  COM_GPIOSCL->DATAOUTCLR = COM_SCL_PIN_MASK; // pull to GND [page 213]
}
#endif // 0

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

// static uint8_t read_int_SCL(void) {
//   return !!(INT_GPIOSCL->DATA & INT_SCL_PIN_MASK);
// }

static uint8_t is_int_i2c_busy(void) {
  return int_i2c.state != INT_I2C_IDLE;
}

/* ========================
   GPIO Interrupt Handler
   ======================== */
// Triggered on rising/falling edges of SDA or SCL
void GPIOA_IRQHandler(void) {
  perform_GPIOA_IRQ_com_event(); // communication
  // perform_GPIOA_IRQ_int_event(); // arbitration loss
}

static void perform_GPIOA_IRQ_com_event(void) {
  if (COM_GPIOSCL->INTSTATUS & COM_SCL_PIN_MASK) { // scl changes
    if (COM_GPIOSCL->INTPOLSET & COM_SCL_PIN_MASK) { // high
      com_i2c.scl = 1;
      perform_SCL_raise_action(); // read data from the master
      COM_GPIOSDA->INTPOLCLR = COM_SCL_PIN_MASK; // set interrupt by low level
      COM_GPIOSDA->INTSTATUS = COM_SCL_PIN_MASK; // clear the interrupt
      return;
    }
    // low
    com_i2c.scl = 0;
    perform_SCL_fall_action(); // write data to the master
    COM_GPIOSDA->INTPOLSET = COM_SCL_PIN_MASK; // set interrupt by high level
    COM_GPIOSDA->INTSTATUS = COM_SCL_PIN_MASK; // clear the interrupt
    return;
  }

  if (COM_GPIOSDA->INTSTATUS & COM_SDA_PIN_MASK) { // sda changed
    if (COM_GPIOSDA->INTPOLSET & COM_SDA_PIN_MASK) { // high
      com_i2c.sda = 1;

      if (com_i2c.scl) {
        perform_SDA_STOP();
      }

      COM_GPIOSDA->INTPOLCLR = COM_SDA_PIN_MASK;
      COM_GPIOSDA->INTSTATUS = COM_SDA_PIN_MASK; // clear the interrupt
      return;
    }
    // low
    com_i2c.sda = 0;
    if (com_i2c.scl) {
      perform_SDA_START();
    }

    COM_GPIOSDA->INTPOLSET = COM_SDA_PIN_MASK;
    COM_GPIOSDA->INTSTATUS = COM_SDA_PIN_MASK; // clear the interrupt
    return;
  }
  
  GPIOA->INTSTATUS = GPIOA->INTSTATUS; // reset all other interrupts
}

static void perform_SCL_fall_action(void) {
  switch (com_i2c.state) {
  case COM_I2C_WDATA:
    ((com_i2c.byte >> com_i2c.bit) & 1) ? release_com_SDA() : pulldown_com_SDA();
    break;

  case COM_I2C_WACK:
    pulldown_com_SDA();
    break;

  default:
    release_com_SDA();
    break;
  }
}

static void perform_SCL_raise_action(void) {
  switch (com_i2c.state) {
  case COM_I2C_START:
    com_i2c.bit = 6;
    com_i2c.addr = 0;
    com_i2c.state = COM_I2C_ADDR;
  case COM_I2C_ADDR:
    com_i2c.addr |= read_com_SDA() << com_i2c.bit;
    if (com_i2c.bit > 0) {
      com_i2c.bit--;
      break;
    }
    com_i2c.p_id = com_i2c.addr << 1; // set the index of the page
    if (!CHECK_ADDR(com_i2c.p_id)) { // wrong address ( not 0x50 (A0) or 0x51 (A2) )
      com_i2c.state = COM_I2C_IDLE;
      break;
    }
    com_i2c.state = COM_I2C_RW;
    break;

  case COM_I2C_RW:
    com_i2c.rw = read_com_SDA();
    if (!com_i2c.rw) { // receive data from master
      com_i2c.l_addr = 0;
      com_i2c.f_raddr = 1; // read the local address in the selected page
    }
    com_i2c.state = COM_I2C_WACK;
    break;
  
  case COM_I2C_WACK:
    pulldown_com_SDA();
    com_i2c.bit = 7;
    if (com_i2c.f_raddr) {
      com_i2c.f_raddr = 0;
      com_i2c.state = COM_I2C_RADDR;
      break;
    }
    if (com_i2c.rw) { // write enable
      com_i2c.l_addr &= 0x7F;
      com_i2c.byte = com_I2C_Read_data(com_i2c.l_addr);
      com_i2c.l_addr = (com_i2c.l_addr + 1) & 0x7F; // same overlap logic
      com_i2c.state = COM_I2C_WDATA;
    }
    else { // read enable
      com_i2c.byte = 0;
      com_i2c.state = COM_I2C_RDATA;
    }
    break;
    
  case COM_I2C_RACK:
    com_i2c.ack = read_com_SDA();
    if (com_i2c.ack) {
      com_i2c.state = COM_I2C_IDLE;
      break;
    }
    com_i2c.bit = 7;
    com_i2c.l_addr &= 0x7F;
    com_i2c.byte = com_I2C_Read_data(com_i2c.l_addr);
    com_i2c.l_addr = (com_i2c.l_addr + 1) & 0x7F; // same overlap logic
    com_i2c.state = COM_I2C_WDATA;
    break;
  
  case COM_I2C_WDATA:
    if (com_i2c.bit > 0) {
      com_i2c.bit--;
      break;
    }
    com_i2c.state = COM_I2C_RACK;
    break;

  case COM_I2C_RADDR:
    com_i2c.l_addr |= read_com_SDA() << com_i2c.bit;
    if (com_i2c.bit > 0) {
      com_i2c.bit--;
      break;
    }
    com_i2c_addres_set(); // save the address untill another address will be written
    com_i2c.state = COM_I2C_WACK;
    break;
  
  case COM_I2C_RDATA:
    com_i2c.byte |= read_com_SDA() << com_i2c.bit;
    if (com_i2c.bit > 0) {
      com_i2c.bit--;
      break;
    }
    com_i2c.l_addr &= 0x7F;
    com_I2C_Write_data(com_i2c.byte, com_i2c.l_addr);
    com_i2c.l_addr = (com_i2c.l_addr + 1) & 0x7F; // same overlap logic
    com_i2c.state = COM_I2C_WACK;
    break;
  
  default:
    break;
  }
}

static void perform_SDA_START(void) {
  com_i2c.state = COM_I2C_START;
}

static void perform_SDA_STOP(void) {
  //com_i2c_addres_clear(); // unlink FLASH page
  com_i2c.state = COM_I2C_IDLE;
}

static void perform_int_tic0(void) {
  switch (int_i2c.state) {
    case INT_I2C_START:
      release_int_SDA();   
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
      if (int_i2c.rx_id >= int_i2c.rx_size) { // not waiting for bytes
        release_int_SDA(); // send nack. the buffer is full
        break;
      }
      pulldown_int_SDA(); // send ack
      break;
    case INT_I2C_RDATA:
      release_int_SDA();
      break;
    case INT_I2C_WDATA:
      ((int_i2c.byte >> int_i2c.bit) & 1) ? release_int_SDA() : pulldown_int_SDA();
      break;
    case INT_I2C_STOP:
      pulldown_int_SDA(); // perform stop sequence
      break;
    default:
      break;
  }
}

static void perform_int_tic1(void) {
  release_int_SCL();
}

static void perform_int_tic2(void) {
  if (!read_int_SCL()) {
    int_i2c.stretch = 1;
    return;
  }
  
  switch (int_i2c.state) {
    case INT_I2C_START:
      pulldown_int_SDA();
      break;
    case INT_I2C_RACK:
      int_i2c.ack = read_int_SDA();
      break;
    case INT_I2C_RDATA:
      int_i2c.byte |= read_int_SDA() << int_i2c.bit;
      break;
    case INT_I2C_STOP:
      release_int_SDA();
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
  
  switch (int_i2c.state) {
    case INT_I2C_START:
      int_i2c.bit = 6; // 7 bits for the address
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
      if (int_i2c.ack) {
        int_i2c.error = 1;
        int_i2c.state = INT_I2C_STOP;
        break;
      }
      if (int_i2c.tx_id >= int_i2c.tx_size) { // nothing to transmit
        if (int_i2c.tx_size) { // some data transmited
          int_i2c.tx_size = 0;
          int_i2c.state = INT_I2C_START;
        }
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
    perform_int_tic0(); // update SDA
    int_i2c.tic++;
    break;
  case 1:
    perform_int_tic1(); // SCL -> HIGH
    int_i2c.tic++;
    break;
  case 2:
    perform_int_tic2(); // read data | check stretching
    int_i2c.tic++;
    break;
  case 3:
    perform_int_tic3(); // SCL -> LOW | update state
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

uint8_t int_I2C_read(uint8_t addr, uint8_t *rx_buff, uint8_t rx_len) {
  int_I2C_start_read(addr, 0x0, 0, rx_buff, rx_len);
  uint8_t status = 0;
  do {
    status = int_I2C_read_complete();
  } while (status == 2); // BUSY
  
  return status == 0 ? 0 : 1;
}

uint8_t int_I2C_request(uint8_t addr, const uint8_t* tx_buff, uint8_t tx_len, uint8_t* rx_buff, uint8_t rx_len) {
  int_I2C_start_read(addr, tx_buff, tx_len, rx_buff, rx_len);
  uint8_t status = 0;
  do {
    status = int_I2C_read_complete();
  } while (status == 2); // BUSY
  
  return status == 0 ? 0 : 1;
}

uint8_t int_I2C_write(uint8_t addr, const uint8_t *tx_buff, uint8_t tx_len) {
  int_I2C_start_write(addr, tx_buff, tx_len);
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
