#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
  
#include "K1921VK035.h"
#include "../inc/flash_if.h"
#include <stdint.h>
#include <string.h>

#define W_SIZE (8) // the size of the flash word (byte)
#define R_SIZE (4) // the size of the ine data register (bytes)

static int8_t wait_ready(){
  volatile int i = 1000000;
  while (i--) {
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
  MFLASH->CMD = (1 << MFLASH_CMD_ERSEC_Pos) | ((uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos); // perform erase [page 256]
  return wait_ready();
}

int8_t flash_read(uint32_t addr, uint8_t* data, uint32_t size) {
  uint32_t Data32[2];
	if (wait_ready()) {
    return -1; // timeout
  }

  for (uint32_t off = 0; off < size; off += W_SIZE) {
    const uint32_t remain = size - off;
    MFLASH->ADDR = addr + off; // [page 255]
    MFLASH->CMD = (1 << MFLASH_CMD_RD_Pos) | ((uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos); // perform erase [page 256]
    if(wait_ready()) {
      return -1; // timeout
    }
    
    Data32[0] = MFLASH->DATA[0].DATA;
    Data32[1] = MFLASH->DATA[1].DATA;
		memcpy(&data[off], Data32, remain > W_SIZE ? W_SIZE : remain);
  }
  
  return 0; // ok
}

int8_t flash_write(uint32_t addr, const uint8_t* data, uint32_t size) {
  uint32_t Data32[2];
  if (wait_ready()) {
    return -1; // timeout
  }

  for(uint32_t off = 0; off < size; off += W_SIZE){
    const uint32_t remain = size - off;
    MFLASH->ADDR = addr + off; // [page 255]
    memcpy(Data32, &data[off], remain > W_SIZE ? W_SIZE : remain);
    
    MFLASH->DATA[0].DATA = Data32[0];
    MFLASH->DATA[1].DATA = Data32[1];
    
    MFLASH->CMD = (1 << MFLASH_CMD_WR_Pos) | ((uint32_t)MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos); // perform erase [page 256]
    
    if(wait_ready()) {
      return -1; // timeout
    }
  }
  
  return 0; // ok
}

int8_t flash_update(uint32_t addr, const uint8_t* data, uint32_t size) {
  if (flash_page_erase(addr)) {
    return -1; // 
  }
  
  if (flash_write( addr, data, size)) {
    return -1; // 
  }
	return 0; // ok
}

#ifdef __cplusplus
}
#endif // __cplusplus
