#ifndef _I2C_MASTER_H
#define _I2C_MASTER_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

/**
 * @param pclk_hz input clock frequency
 * @param scl_hz I2C frequency
 */
//void i2cm_init(uint32_t pclk_hz, uint32_t scl_hz);

/**
 * @brief The function trys ro get complete message from the I2C bus.
 * @param addr7[OUT] address of the source
 * @param data[OUT] data from the source
 * @param max_len[IN] maximum length that can be writen to the data
 * @return actual length of the message. 0 - no message was read
 */
//uint16_t i2cm_read(uint8_t* addr7, uint8_t* data, uint8_t max_len);

/**
 * @brief The function sends the message from the I2C bus.
 * @param addr7[IN] address of the source
 * @param data[OUT] data for sending
 * @param max_len[IN] maximum length that can be writen to the data
 */
//void i2cm_write(uint8_t addr7, const uint8_t* data, uint8_t len);

#ifdef __cplusplus
}
#endif // __cplusplus
#ednif // _I2C_MASTER_H
