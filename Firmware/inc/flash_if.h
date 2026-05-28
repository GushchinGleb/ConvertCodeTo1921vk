#ifndef FLASH_IF_H
#define FLASH_IF_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief
 * Flash locations (adjust within 64KB program flash) 
 * The last 3 flash pages (1KB is page size) of flash is reserved for 3 user data pages.
 * The maximum program capasity is 61KB.
 */
#define FLASH_A0    (0x0000F400)
#define FLASH_A2    (FLASH_A0   + 0x0400)
#define FLASH_A2_UP (FLASH_A2   + 0x0400)

/**
 * @param addr[IN] address of the page
 */
int8_t flash_page_erase(uint32_t addr);

/**
 * @param addr[IN] address of the data on the flash
 * @param data[OUT] data from the page
 * @param size[IN] size of the data on the flash
 */
int8_t flash_read(uint32_t addr, uint8_t* data, uint32_t size);

/**
 * @param addr[IN] address of the data on the flash
 * @param data[IN] data to the page
 * @param size[IN] size of the data on the flash
 */
int8_t flash_write(uint32_t addr, const uint8_t* data, uint32_t size);

/**
 * @param addr[IN] address of the data on the flash
 * @param data[IN] data to the page
 * @param size[IN] size of the data on the flash
 */
int8_t flash_update(uint32_t addr, const uint8_t* data, uint32_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FLASH_IF_H
