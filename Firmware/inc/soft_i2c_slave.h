#ifndef _SOFT_I2C_SLAVE_H
#define _SOFT_I2C_SLAVE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

void soft_I2C_init(void);

void I2C_Write_data(uint8_t byte, uint8_t I2C_Current_Address);

uint8_t I2C_Read_data(uint8_t I2C_Current_Address);

uint8_t* I2C_Decode_page_address(uint8_t Address, uint8_t I2C_Current_Page);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SOFT_I2C_SLAVE_H
