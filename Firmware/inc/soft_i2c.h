#ifndef _SOFT_I2C_SLAVE_H
#define _SOFT_I2C_SLAVE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

// I2C communicates with the external computer.
#define COM_GPIOSDA GPIOA
#define COM_SDA_PIN PIN1
#define COM_SDA_PIN_MASK (1 << 1)

#define COM_GPIOSCL GPIOA
#define COM_SCL_PIN PIN0
#define COM_SCL_PIN_MASK (1 << 0)

// I2C communicates with the internal chips.
#define INT_GPIOSDA GPIOA
#define INT_SDA_PIN PIN5
#define INT_SDA_PIN_MASK (1 << 5)

#define INT_GPIOSCL GPIOA
#define INT_SCL_PIN PIN4
#define INT_SCL_PIN_MASK (1 << 4)

/**
 * @brief The funstions initialize two software uart instances.
 * The ports are configurated above.
 * 1. To external devise to command sending.
 * SLAVE  | SCL - A0 | SDA - A1
 * 2. To MALD and MATA
 * MASTER | SCL - A4 | SDA - A5
 */
void soft_I2C_init(void);

// ==========================================
// EXTERNAL (COMMAND) I2C API
// ==========================================

void com_I2C_Write_data(uint8_t byte, uint8_t I2C_Current_Address);

uint8_t com_I2C_Read_data(uint8_t I2C_Current_Address);

uint8_t* com_I2C_Decode_page_address(uint8_t Address, uint8_t I2C_Current_Page);

// ==========================================
// INTERNAL I2C API
// 
// Valid workflow:
// int_I2C_start_write / int_I2C_start_read -> int_I2C_operation_complete -> int_I2C_start_write / int_I2C_start_read ...
//
// ==========================================

/**
 * @brief The function performs non-blocking write of data over internal I2C.
 * @param addr[IN] destinations address
 * @param data[IN] data for transfer the buffer must containt the data untill the transaction ended
 */
void int_I2C_start_write(uint8_t addr, const uint8_t *data, uint8_t len);

/**
 * @brief The function sends additional data and performs non-blocking read of data over internal I2C.
 * @param addr[IN] destinations address
 * @param wr_data[IN] additional data for the adders (can be NULL)
 * @param we_data_size[IN] the length of the additional data
 * @param buffer[OUT] data from the transfer
 * @param size[IN] count of the bytes in the requested data
 */
void int_I2C_start_read(uint8_t addr, const uint8_t* wr_data, uint32_t wr_data_size, uint8_t *buffer, uint32_t size);

/**
 * @brief The fuction checks the status of the last opetation.
 * @retunr 0 -- the last operation complete
 * @return 1 -- the last operation failed
 * @return 2 -- the last operation is still in process
 */
uint8_t int_I2C_read_complete(void);
/**
 * @brief The fuction checks the status of the last opetation.
 * @retunr 0 -- the last operation complete
 * @return 1 -- the last operation failed
 * @return 2 -- the last operation is still in process
 */
uint8_t int_I2C_write_complete(void);

/**
 * @brief The function performs blocking write of data over internal I2C.
 * @param addr[IN] destinations address
 * @param data[IN] data for transfer the buffer must containt the data untill the transaction ended
 * @retunr 0 -- the last operation complete
 * @return 1 -- the last operation failed
 */
uint8_t int_I2C_write(uint8_t addr, const uint8_t *data, uint8_t len);

/**
 * @brief The function performs blocking read of data over internal I2C.
 * @param addr[IN] destinations address
 * @param data[IN] data for transfer the buffer must containt the data untill the transaction ended
 * @retunr 0 -- the last operation complete
 * @return 1 -- the last operation failed
 */
uint8_t int_I2C_read(uint8_t addr, uint8_t *buffer, uint8_t len);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SOFT_I2C_SLAVE_H
