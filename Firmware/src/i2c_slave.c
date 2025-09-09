#include "i2c_slave.h"
#include "eeprom_a0a2.h"
#include "sfp28.h"

// Use I2C1 as SFP slave (addresses 0x50/0x51). We’ll switch the page based on the upper address byte (as in SFP A2 paging).

static volatile uint8_t s_cur_ptr = 0;
static volatile uint8_t s_cur_dev = I2C_ADDR_A0;

void i2cs_init(uint8_t addr7){
  // Program ADDR with addr7, set SAEN to enable address compare; enable module. :contentReference[oaicite:27]{index=27}
  // Enable IRQ in NVIC and I2C interrupt enable bit (ST flag).
}

static inline uint8_t eep_read(uint8_t dev, uint8_t off){
  const eep_page_t* p0 = (dev==I2C_ADDR_A0) ? &g_a0_low : &g_a2_low;
  return p0->bytes[off];
}

static inline void eep_write(uint8_t dev, uint8_t off, uint8_t v){
  eep_page_t* p0 = (dev==I2C_ADDR_A0) ? &g_a0_low : &g_a2_low;
  p0->bytes[off]=v;
}

void i2cs_isr(void){
  // Read ST/CST to determine SR/STA/STOP, RD/WR, TX/RX paths. :contentReference[oaicite:28]{index=28}
  // Emulate 24C02-like behavior:
  // - On write: first byte after address is memory pointer, then data.
  // - On read: send from current pointer, autoinc, wrap at 0x80.
  // This mirrors your C8051 SMBus ISR behavior. :contentReference[oaicite:29]{index=29}
}
