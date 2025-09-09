#pragma once
#include <stdint.h>

// ===== I2C addresses =====
#define I2C_ADDR_A0   0x50u  // SFP A0 page (slave)
#define I2C_ADDR_A2   0x51u  // SFP A2 page (slave)
#define I2C_ADDR_MASC 0x4Fu  // 0x9E >> 1 (7-bit) (master)

// ===== GPIO mapping (adjust to your PCB) =====
// Use the VK035 GPIO & altfunc mux to route pins to I2C0/I2C1, etc.
// These are placeholders—map to actual ports/pins in your schematic.
#define PIN_TX_DISABLE   GPIOX_PIN_Y    // output to module
#define PIN_TX_FAULT     GPIOX_PIN_Z    // input from module
#define PIN_LOS          GPIOX_PIN_W    // input from module
#define PIN_RS0          GPIOX_PIN_V    // output to module
#define PIN_RS1          GPIOX_PIN_U    // output to module

// ===== Clocks =====
// We’ll run from PLL for 100 MHz SYSCLK if HSE present; otherwise OSI.
