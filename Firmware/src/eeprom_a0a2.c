#include "../inc/eeprom_a0a2.h"
#include "../inc/flash_if.h"
#include <string.h>

// Choose Flash locations (adjust within 64KB program flash)
// Example: last 512B split into 4×128B
#define FLASH_A0_LOW  (0x0000F800u)
#define FLASH_A0_HI   (0x0000F880u)
#define FLASH_A2_LOW  (0x0000F900u)
#define FLASH_A2_HI   (0x0000F980u)

eep_page_t g_a0_low, g_a0_hi, g_a2_low, g_a2_hi;

void eep_pages_init_from_flash(void){
  uint32_t tmp[32];
  flash_read128(FLASH_A0_LOW,  tmp); memcpy(g_a0_low.bytes,  tmp, 128);
  flash_read128(FLASH_A0_HI,   tmp); memcpy(g_a0_hi .bytes, tmp, 128);
  flash_read128(FLASH_A2_LOW,  tmp); memcpy(g_a2_low.bytes, tmp, 128);
  flash_read128(FLASH_A2_HI,   tmp); memcpy(g_a2_hi .bytes, tmp, 128);
}

void eep_pages_commit_to_flash(void){
  uint32_t tmp[32];
  flash_page_erase(FLASH_A0_LOW);
  memcpy(tmp, g_a0_low.bytes, 128);  flash_write128(FLASH_A0_LOW, tmp);
  memcpy(tmp, g_a0_hi.bytes,  128);  flash_write128(FLASH_A0_HI,  tmp);
  memcpy(tmp, g_a2_low.bytes, 128);  flash_write128(FLASH_A2_LOW, tmp);
  memcpy(tmp, g_a2_hi.bytes,  128);  flash_write128(FLASH_A2_HI,  tmp);
}
