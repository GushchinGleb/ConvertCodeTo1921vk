#ifndef _SOFT_SLAVE_I2C_H
#define _SOFT_SLAVE_I2C_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

/**
 * @brief Bit-banged I2C slave on SFP_SCL (A4) / SFP_SDA (A5).
 *
 * Responds to addresses I2C_ADDR_A0 (0x50) and I2C_ADDR_A2 (0x51).
 * Backing storage is the existing A0_Page / A2_Page / A2Up_Page buffers
 * declared in eeprom_a0a2.c.
 *
 * Uses GPIOA edge interrupts (GPIOA_IRQn). Call once after the system
 * clock is stable and before any traffic is expected on the bus.
 */
void soft_i2c_slave_init(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SOFT_SLAVE_I2C_H
