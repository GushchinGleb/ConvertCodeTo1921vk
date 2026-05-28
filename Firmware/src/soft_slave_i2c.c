#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

#include "K1921VK035.h"

#include "../inc/board.h"
#include "../inc/soft_slave_i2c.h"
#include "../inc/sfp28.h"

/**
 * Bit-banged I2C slave on A4 (SCL) / A5 (SDA), GPIOA.
 *
 * Optimisations vs the textbook version:
 *   - SDA stays in open-drain mode with OUTEN held high; we toggle DATAOUT
 *     only, so release / drive-low are each a single 32-bit store.
 *   - Two precomputed page bases (page_lo, page_hi) are latched at address
 *     match, eliminating per-byte branches on the matched address.
 *   - Helpers force-inlined to defeat -O0 / -O1.
 *   - State variables are non-volatile (single-context — only the ISR mutates
 *     them, init runs before NVIC enable).
 */

extern A0_Page_t   A0_Page;
extern A2_Page_t   A2_Page;
extern A2Up_Page_t A2Up_Page;

#if defined(__ARMCC_VERSION)
  #define ALWAYS_INLINE static __forceinline
#else
  #define ALWAYS_INLINE static __attribute__((always_inline)) inline
#endif

typedef enum {
  S_IDLE = 0,      // bus idle / address mismatch — wait for next START
  S_ADDR,          // shifting in address byte (7 bits + R/W)
  S_ADDR_ACK,      // we drove SDA low to ACK the address
  S_REG,           // shifting in register-pointer byte (write phase)
  S_REG_ACK,       // we drove SDA low to ACK the register byte
  S_RX,            // shifting in a data byte from master (write)
  S_RX_ACK,        // we drove SDA low to ACK a received data byte
  S_TX,            // shifting out a data byte to master (read)
  S_TX_ACK         // released SDA, sampling master ACK/NACK
} i2c_state_t;

static i2c_state_t state      = S_IDLE;
static uint8_t     bit_cnt    = 0;     // bits processed this byte
static uint8_t     shift_byte = 0;     // RX shift register / TX shift-out
static uint8_t     is_read    = 0;     // R/W bit from address
static uint8_t     reg_ptr    = 0;     // current page offset
static uint8_t     got_nack   = 0;     // sampled bit during TX ACK

// Page bases latched at address match; offsets in [0..127] index page_lo,
// offsets in [128..255] index page_hi[off-128]. For A0 both point at the
// same 128-byte buffer (master shouldn't read past 127 there).
static uint8_t * page_lo = (uint8_t *)0;
static uint8_t * page_hi = (uint8_t *)0;

//----------------------------------------------------------------------------
// SDA line control. Open-drain + OUTEN held set at init time, so:
//   - DATAOUTSET = SDA -> DATAOUT bit = 1 -> pin Hi-Z (line pulls high).
//   - DATAOUTCLR = SDA -> DATAOUT bit = 0 -> pin pulls low.
// Each is a single peripheral store.
//----------------------------------------------------------------------------
ALWAYS_INLINE void sda_release(void) {
  GPIO_SFP_I2C->DATAOUTSET = SFP_SDA_MASK;
}

ALWAYS_INLINE void sda_drive_low(void) {
  GPIO_SFP_I2C->DATAOUTCLR = SFP_SDA_MASK;
}

ALWAYS_INLINE void put_tx_bit(uint8_t b) {
  if (b & 0x80u) GPIO_SFP_I2C->DATAOUTSET = SFP_SDA_MASK;
  else           GPIO_SFP_I2C->DATAOUTCLR = SFP_SDA_MASK;
}

ALWAYS_INLINE uint8_t page_load(uint8_t off) {
  return (off < 128u) ? page_lo[off] : page_hi[(uint8_t)(off - 128u)];
}

ALWAYS_INLINE void page_store(uint8_t off, uint8_t v) {
  if (off < 128u) page_lo[off] = v;
  else            page_hi[(uint8_t)(off - 128u)] = v;
}

ALWAYS_INLINE void go_idle(void) {
  sda_release();
  state   = S_IDLE;
  bit_cnt = 0;
}

//----------------------------------------------------------------------------
// Init: configure A4/A5 as GPIO open-drain with pullups, arm both-edge
//       interrupts, enable GPIOA NVIC line.
//----------------------------------------------------------------------------
void soft_i2c_slave_init(void) {
  // Disable while configuring — protects against stale latched edges.
  NVIC_DisableIRQ(GPIOA_IRQn);
  GPIO_SFP_I2C->INTENCLR = SFP_SCL_MASK | SFP_SDA_MASK;

  // Take A0/A1 off the hardware-I2C alt function and back to plain GPIO.
  GPIO_SFP_I2C->ALTFUNCCLR = SFP_SCL_MASK | SFP_SDA_MASK;

  // Open-drain + pullup on both lines.
  GPIO_SFP_I2C->PULLMODE_bit.SFP_SCL_PIN = 0x1;
  GPIO_SFP_I2C->PULLMODE_bit.SFP_SDA_PIN = 0x1;
  GPIO_SFP_I2C->OUTMODE_bit.SFP_SCL_PIN  = 0x1;
  GPIO_SFP_I2C->OUTMODE_bit.SFP_SDA_PIN  = 0x1;

  // SDA: OUTEN held set, DATAOUT high -> pin Hi-Z (released, line pulls high).
  GPIO_SFP_I2C->DATAOUTSET = SFP_SDA_MASK;
  GPIO_SFP_I2C->OUTENSET   = SFP_SDA_MASK;
  // SCL: input only — we never stretch the clock.
  GPIO_SFP_I2C->OUTENCLR   = SFP_SCL_MASK;

  GPIO_SFP_I2C->DENSET = SFP_SCL_MASK | SFP_SDA_MASK;

  // Reset state.
  state    = S_IDLE;
  bit_cnt  = 0;
  reg_ptr  = 0;
  page_lo  = A0_Page.Bytes; // safe defaults so a stray ISR can't dereference null
  page_hi  = A0_Page.Bytes;

  // Edge-sensitive, every edge, on both pins.
  GPIO_SFP_I2C->INTTYPESET = SFP_SCL_MASK | SFP_SDA_MASK;
  GPIO_SFP_I2C->INTEDGESET = SFP_SCL_MASK | SFP_SDA_MASK;

  // Clear any stale latched flags, then unmask.
  GPIO_SFP_I2C->INTSTATUS = SFP_SCL_MASK | SFP_SDA_MASK;
  GPIO_SFP_I2C->INTENSET  = SFP_SCL_MASK | SFP_SDA_MASK;

  // Highest priority — we must service edges within an SCL half-period.
  NVIC_SetPriority(GPIOA_IRQn, 0);
  NVIC_EnableIRQ(GPIOA_IRQn);
}

//----------------------------------------------------------------------------
// Interrupt handler — services SCL/SDA edges only; other GPIOA pins are
// untouched (only their INTSTATUS bits, which we never enable, would latch).
//----------------------------------------------------------------------------
void GPIOA_IRQHandler(void) {
	//TEST
	GPIO_IC_RS0->DATAOUTSET = IC_RS0_MASK;
	//TEST
  uint32_t status = GPIO_SFP_I2C->INTSTATUS & (SFP_SCL_MASK | SFP_SDA_MASK);
  GPIO_SFP_I2C->INTSTATUS = status; // W1C latched bits

  uint32_t pins    = GPIO_SFP_I2C->DATA;
  uint32_t scl_now = pins & SFP_SCL_MASK;
  uint32_t sda_now = pins & SFP_SDA_MASK;

  // ---- START / STOP: SDA edge while SCL is high ----
  if ((status & SFP_SDA_MASK) && scl_now) {
    if (sda_now == 0) {
      // START or repeated START
      sda_release();
      state      = S_ADDR;
      bit_cnt    = 0;
      shift_byte = 0;
    } else {
      // STOP
      go_idle();
    }
	//TEST
	GPIO_IC_RS0->DATAOUTCLR = IC_RS0_MASK;
	//TEST
    return;
  }

  if ((status & SFP_SCL_MASK) == 0) {
	//TEST
	GPIO_IC_RS0->DATAOUTCLR = IC_RS0_MASK;
	//TEST
		return;
	}

  if (scl_now) {
    // -------------------- SCL rising edge: SAMPLE --------------------
    switch (state) {
      case S_ADDR:
      case S_REG:
      case S_RX:
        shift_byte = (uint8_t)((shift_byte << 1) | (sda_now ? 1u : 0u));
        bit_cnt++;
        break;

      case S_TX_ACK:
        // Master drives SDA: 0 = ACK (continue), 1 = NACK (end).
        got_nack = sda_now ? 1u : 0u;
        break;

      default:
        break;
    }
  } else {
    // -------------------- SCL falling edge: DRIVE --------------------
    switch (state) {
      case S_ADDR:
        if (bit_cnt == 8) {
          uint8_t addr7 = (uint8_t)(shift_byte >> 1);
          is_read = (uint8_t)(shift_byte & 1u);
          if (addr7 == I2C_ADDR_A0) {
            page_lo = A0_Page.Bytes;
            page_hi = A0_Page.Bytes; // A0 is 128 B; off >= 128 wraps mod 128
            sda_drive_low();
            state = S_ADDR_ACK;
          } else if (addr7 == I2C_ADDR_A2) {
            page_lo = A2_Page.Bytes;
            page_hi = A2Up_Page.Bytes;
            sda_drive_low();
            state = S_ADDR_ACK;
          } else {
            go_idle();
          }
        }
        break;

      case S_ADDR_ACK:
        if (is_read) {
          // Master will read: load byte, drive MSB before next SCL rise.
          uint8_t b = page_load(reg_ptr);
          put_tx_bit(b);
          shift_byte = (uint8_t)(b << 1);
          bit_cnt    = 1;
          state      = S_TX;
        } else {
          sda_release();
          bit_cnt    = 0;
          shift_byte = 0;
          state      = S_REG;
        }
        break;

      case S_REG:
        if (bit_cnt == 8) {
          reg_ptr = shift_byte;
          sda_drive_low();
          state = S_REG_ACK;
        }
        break;

      case S_REG_ACK:
        sda_release();
        bit_cnt    = 0;
        shift_byte = 0;
        state      = S_RX;
        break;

      case S_RX:
        if (bit_cnt == 8) {
          page_store(reg_ptr, shift_byte);
          reg_ptr++;
          sda_drive_low();
          state = S_RX_ACK;
        }
        break;

      case S_RX_ACK:
        sda_release();
        bit_cnt    = 0;
        shift_byte = 0;
        state      = S_RX;
        break;

      case S_TX:
        if (bit_cnt < 8) {
          put_tx_bit(shift_byte);
          shift_byte = (uint8_t)(shift_byte << 1);
          bit_cnt++;
        } else {
          // 8 bits sent — release SDA so master can ACK/NACK on next rise.
          sda_release();
          got_nack = 0;
          state    = S_TX_ACK;
        }
        break;

      case S_TX_ACK:
        if (got_nack) {
          // Master is done — wait for STOP (SDA edge handler will catch it).
          go_idle();
        } else {
          reg_ptr++;
          uint8_t b = page_load(reg_ptr);
          put_tx_bit(b);
          shift_byte = (uint8_t)(b << 1);
          bit_cnt    = 1;
          state      = S_TX;
        }
        break;

      default:
        break;
    }
  }
	//TEST
	GPIO_IC_RS0->DATAOUTCLR = IC_RS0_MASK;
	//TEST
}

#ifdef __cplusplus
}
#endif // __cplusplus
