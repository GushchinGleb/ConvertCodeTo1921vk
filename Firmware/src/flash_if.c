#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
#include "K1921VK035.h"
#include "../inc/flash_if.h"
#include <stdint.h>
#include <string.h>

#define W_SIZE (8) // the size of the flash word (byte)

static int8_t wait_ready(){
  for (volatile uint32_t i = 0; i < 1000000u; i++) {
    if(!MFLASH->STAT_bit.BUSY) {
			return 0;
		}
  }
  return -1; // timeout
}

int8_t flash_page_erase(uint32_t addr) {
	if (wait_ready()) {
		return -1; // timeout
	}

  MFLASH->ADDR = addr; // [page 255]
	MFLASH->CMD = 1 << MFLASH_CMD_ERSEC_Pos | (uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos; // perform erase [page 256]
	return wait_ready();
}

int8_t flash_read(uint32_t addr, uint8_t* data, uint32_t size) {
	if (wait_ready()) {
		return -1; // timeout
	}

	for (uint32_t off = 0; off < size; off += 4) {
		const uint32_t remain = size - off;
    MFLASH->ADDR = addr + off; // [page 255]
	  MFLASH->CMD = 1 << MFLASH_CMD_RD_Pos | (uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos; // perform erase [page 256]
		if(!wait_ready()) {
			return -1; // timeout
		}
		
		memcpy(&data[off], MFLASH->DATA, remain > W_SIZE ? W_SIZE : remain);
  }
	
	return 0; // ok
}

int8_t flash_write(uint32_t addr, const uint8_t* data, uint32_t size) {
	if (wait_ready()) {
		return -1; // timeout
	}

	for(uint32_t off = 0; off < size; off += W_SIZE){
		const uint32_t remain = size - off;
    MFLASH->ADDR = addr + off; // [page 255]
		uint8_t data_prep[8] = {0};
		memcpy(data_prep, &data[off], remain > W_SIZE ? W_SIZE : remain);
		memcpy(MFLASH->DATA, data_prep, W_SIZE);
	  MFLASH->CMD = 1 << MFLASH_CMD_WR_Pos | (uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos; // perform erase [page 256]
		
    if(!wait_ready()) {
			return -1; // timeout
		}
  }
	
	return 0; // ok
}

#ifdef __cplusplus
}
#endif // __cplusplus
