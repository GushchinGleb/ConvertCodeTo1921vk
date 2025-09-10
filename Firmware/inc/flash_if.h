#ifndef FLASH_IF_H
#define FLASH_IF_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>
#include <stdbool.h>

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

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FLASH_IF_H
