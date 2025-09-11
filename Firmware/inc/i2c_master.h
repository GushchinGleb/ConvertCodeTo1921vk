#ifndef _I2C_MASTER_H
#define _I2C_MASTER_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <K1921VK035.h>
#include <stdint.h>

#define I2C0        (I2C)

/* Driver return codes */
typedef enum {
    I2C_DRV_OK = 0,
    I2C_DRV_ERR_NO_ACK,
    I2C_DRV_ERR_BUS,
    I2C_DRV_ERR_TIMEOUT
} i2c_drv_status_t;

void i2c_init(I2C_TypeDef *i2c,
              uint32_t Fpclk,         /* global frequency (Hz) */
              uint32_t scl_freq);     /* scl frequency (Hz) */

/* Write buffer to 7-bit slave */
i2c_drv_status_t i2c_write_buffer(I2C_TypeDef *i2c,
                                  uint8_t slave_addr,
                                  const uint8_t *buf,
                                  uint32_t len);

/* Read buffer from 7-bit slave */
i2c_drv_status_t i2c_read_buffer(I2C_TypeDef *i2c,
                                 uint8_t slave_addr,
                                 uint8_t *buf,
                                 uint32_t len);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _I2C_MASTER_H
