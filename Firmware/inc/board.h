#ifndef _BOARD_H
#define _BOARD_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

// ===== I2C addresses =====
#define I2C_ADDR_A0   0x50u  // SFP A0 page (slave)
#define I2C_ADDR_A2   0x51u  // SFP A2 page (slave)
#define I2C_ADDR_MASC 0x4Fu  // 0x9E >> 1 (7-bit) (master)

// ===== GPIO mapping (adjust to your PCB) =====
// Use the VK035 GPIO & altfunc mux to route pins to I2C0/I2C1, etc.
// These are placeholders—map to actual ports/pins in your schematic.
// Pin DEV_SCL (A0) internal devices SCL pin (GPIO)
// Pin DEV_SDA (A1) internal devices SDA pin (GPIO)
#define GPIO_DEV_I2C		GPIOA
#define DEV_SCL_PIN			PIN0
#define DEV_SCL_MASK		(1 << 0)
#define DEV_SDA_PIN			PIN1
#define DEV_SDA_MASK		(1 << 1)

// Pin SFP_SCL (A4) external connector SCL pin (GPIO)
// Pin SFP_SDA (A5) external connector SDA pin (GPIO)
#define GPIO_SFP_I2C		GPIOA
#define SFP_SCL_PIN			PIN4
#define SFP_SCL_MASK		(1 << 4)
#define SFP_SDA_PIN			PIN5
#define SFP_SDA_MASK		(1 << 5)

// Pin TX_FAULT (A6) output pin (GPIO)
#define GPIO_TX_FAULT		GPIOA
#define TX_FAULT_PIN		PIN6
#define TX_FAULT_MASK		(1 << 6)
// #define TX_FAULT ((GPIO_TX_FAULT->DATA_bit.VAL & (1 << 6)) >> 6)
// Pin TX_DISABLE (A7) input pin (GPIO)
#define GPIO_TX_DISABLE	GPIOA
#define TX_DISABLE_PIN	PIN7
#define TX_DISABLE_MASK	(1 << 7)
// #define TX_DISABLE ((GPIO_TX_DISABLE->DATA_bit.VAL & (1 << 7)) >> 7)

// Pin RST_TX (A8) output pin (GPIO)
#define GPIO_RST_TX			GPIOA
#define RST_TX_PIN			PIN8
#define RST_TX_MASK			(1 << 8)
// Pin RST_RX (A9) output pin (GPIO)
#define GPIO_RST_RX			GPIOA
#define RST_RX_PIN			PIN9
#define RST_RX_MASK			(1 << 9)

// Pin IC_RS0 (A10) output pin (GPIO)
#define GPIO_IC_RS0 		GPIOA
#define IC_RS0_PIN			PIN10
#define IC_RS0_MASK			(1 << 10)
// Pin IC_RS1 (A11) output pin (GPIO)
#define GPIO_IC_RS1 		GPIOA
#define IC_RS1_PIN			PIN11
#define IC_RS1_MASK			(1 << 11)
  
// Pin RS0 (A12) IN
#define GPIO_RS0				GPIOA
#define RS0_PIN					PIN12
#define RS0_PIN_MASK		(1 << 12)
#define RS0 						((GPIO_RS0->DATA_bit.VAL & (1 << 12)) >> 12)

// Pin LOS (A13) output pin (GPIO)
#define GPIO_LOS				GPIOA
#define LOS_PIN 				PIN13
#define LOS_PIN_MASK		(1 << 13)

// Pin RS1 (A14) IN
#define GPIO_RS1				GPIOA
#define RS1_PIN 				PIN14
#define RS1_PIN_MASK		(1 << 14)
#define RS1 						((GPIO_RS1->DATA_bit.VAL & (1 << 14)) >> 14)
  
// Pin RSSI (B0) analog input pin
#define GPIO_RSSI 			GPIOB
#define RSSI_PIN				PIN0
  
// ===== Clocks =====
// We’ll run from PLL for 100 MHz SYSCLK if HSE present; otherwise OSI.

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _BOARD_H
