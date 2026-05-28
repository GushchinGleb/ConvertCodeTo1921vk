#ifndef _SOFT_MASTER_I2C_H
#define _SOFT_MASTER_I2C_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

int soft_i2c_master_init(void);
int Read_soft_i2c(uint8_t DevAddr, uint8_t RegAddr, uint8_t *buf, uint8_t size);
int Write_soft_i2c(uint8_t DevAddr, uint8_t *buf, uint8_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SOFT_MASTER_I2C_H
