#include "flash_if.h"
#include <string.h>

// Replace with actual base addresses from A.4 regs in your device headers
#define FLASH_BASE   ((volatile uint32_t*)0x40020000)
#define FLASH_ADDR   (*(volatile uint32_t*)(FLASH_BASE + 0x00/4))
#define FLASH_DATA0  (*(volatile uint32_t*)(FLASH_BASE + 0x04/4))
#define FLASH_DATA1  (*(volatile uint32_t*)(FLASH_BASE + 0x08/4))
#define FLASH_CMD    (*(volatile uint32_t*)(FLASH_BASE + 0x24/4))
#define FLASH_STAT   (*(volatile uint32_t*)(FLASH_BASE + 0x28/4))

#define CMD_KEY   (0xC0DEu << 16)
#define CMD_WR    (1u << 1)
#define CMD_RD    (1u << 1)   // RD shares the bit per table; write the correct opcode field for read
#define CMD_ERSEC (1u << 2)

static inline bool wait_ready(void){
  // poll FLASH_STAT BUSY==0, check ERR bits; exact bitfields per A.4.6. :contentReference[oaicite:17]{index=17}
  for(volatile int i=0;i<1000000;i++){
    uint32_t s = FLASH_STAT;
    if((s & (1u<<0))==0) return (s & 0xDEAD0000u)==0; // placeholder ERR mask
  }
  return false;
}

bool flash_page_erase(uint32_t addr){
  FLASH_ADDR = addr;
  FLASH_CMD  = CMD_KEY | CMD_ERSEC;
  return wait_ready();
}

bool flash_write128(uint32_t addr, const uint32_t* p){
  // Write 128 bytes in 64-bit beats via DATA0/DATA1, sequencing CMD.WR each step. :contentReference[oaicite:18]{index=18}
  for(uint32_t off=0; off<128; off+=8){
    FLASH_ADDR = addr + off;
    FLASH_DATA0 = p[0];
    FLASH_DATA1 = p[1];
    FLASH_CMD = CMD_KEY | CMD_WR;
    if(!wait_ready()) return false;
    p += 2;
  }
  return true;
}

bool flash_read128(uint32_t addr, uint32_t* p){
  for(uint32_t off=0; off<128; off+=8){
    FLASH_ADDR = addr + off;
    FLASH_CMD = CMD_KEY | CMD_RD;
    if(!wait_ready()) return false;
    p[0] = FLASH_DATA0;
    p[1] = FLASH_DATA1;
    p += 2;
  }
  return true;
}

bool flash_init(void){ return true; }
