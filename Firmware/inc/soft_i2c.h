#ifndef _SOFT_I2C_SLAVE_H
#define _SOFT_I2C_SLAVE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

// *** CONFIGURATION BEGIN *** //

#define COM_SDA_GPIOA
// #define COM_SDA_GPIOA
#define COM_SCL_GPIOA
// #define COM_SCL_GPIOB
#define INT_SDA_GPIOA
// #define INT_SDA_GPIOB
#define INT_SCL_GPIOA
// #define INT_SCL_GPIOB

#define COM_SDA_PIN PIN5
#define COM_SDA_PIN_MASK (1 << 5)
#define COM_SCL_PIN PIN4
#define COM_SCL_PIN_MASK (1 << 4)
#define INT_SDA_PIN PIN1
#define INT_SDA_PIN_MASK (1 << 1)
#define INT_SCL_PIN PIN0
#define INT_SCL_PIN_MASK (1 << 0)

// ***  CONFIGURATION END  *** //

#if defined(COM_SDA_GPIOA) && defined(COM_SDA_GPIOB)
#error "multiple GPIO for the com_sda pin are defined"
#endif
#if defined(COM_SCL_GPIOA) && defined(COM_SCL_GPIOB)
#error "multiple GPIO for the com_scl pin are defined"
#endif
#if defined(INT_SDA_GPIOA) && defined(INT_SDA_GPIOB)
#error "multiple GPIO for the int_sda pin are defined"
#endif
#if defined(INT_SCL_GPIOA) && defined(INT_SCL_GPIOB)
#error "multiple GPIO for the int_scl pin are defined"
#endif

// I2C communicates with the external computer.
#ifdef COM_SDA_GPIOA
#define COM_GPIOSDA GPIOA
#endif // COM_SDA_GPIOA
#ifdef COM_SDA_GPIOB
#define COM_GPIOSDA GPIOB
#endif // COM_SDA_GPIOB

#ifdef COM_SCL_GPIOA
#define COM_GPIOSCL GPIOA
#endif // COM_SDA_GPIOA
#ifdef COM_SCL_GPIOB
#define COM_GPIOSCL GPIOB
#endif // COM_SDA_GPIOB

// I2C communicates with the internal chips.
#ifdef COM_SDA_GPIOA
#define COM_GPIOSDA GPIOA
#endif // COM_SDA_GPIOA
#ifdef COM_SDA_GPIOB
#define COM_GPIOSDA GPIOB
#endif // COM_SDA_GPIOB
#define INT_GPIOSDA GPIOA

#ifdef COM_SCL_GPIOA
#define COM_GPIOSCL GPIOA
#endif // COM_SDA_GPIOA
#ifdef COM_SCL_GPIOB
#define COM_GPIOSCL GPIOB
#endif // COM_SDA_GPIOB
#define INT_GPIOSCL GPIOA

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

/**
 @brief The function checks connections from the I2C to the master.
 @return {0 - connection success; 1 - SDA connections error; 2 - SCL connection error; 3 - both of the wires not connected}
 */
uint8_t com_I2C_Check_connection(void);

void com_I2C_resset(void);

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
 * @param tx_buff[IN] data to a device
 * @param tx_len[IN] count of the transmited bytes
 * @retunr 0 -- the last operation complete
 * @return 1 -- the last operation failed
 */
uint8_t int_I2C_write(uint8_t addr, const uint8_t *tx_buff, uint8_t tx_len);

/**
 * @brief The function performs blocking read of data over internal I2C.
 * @param addr[IN] source address
 * @param rx_buff[OUT] data from a device
 * @param rx_len[IN] count of the requested bytes
 * @return 0 -- the last operation complete
 * @return 1 -- the last operation failed
 */
uint8_t int_I2C_read(uint8_t addr, uint8_t *rx_buff, uint8_t rx_len);

/**
 * @brief The function performs bloking request.
 * The function sends a request and perform start-without-stop reading operation.
 * @param addr[IN] address of the device (target address)
 * @param tx_buff[IN] data or request to the target
 * @param tx_len[IN] count of the transmited bytes
 * @param rx_buff[OUT] data from the target
 * @param rx_len[IN] count of the requested bytes
 * @retunr 0 -- the last operation complete
 * @return 1 -- the last operation failed
 */
uint8_t int_I2C_request(uint8_t addr, const uint8_t* tx_buff, uint8_t tx_len, uint8_t* rx_buff, uint8_t rx_len);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _SOFT_I2C_SLAVE_H
