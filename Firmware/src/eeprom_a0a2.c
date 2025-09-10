#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/eeprom_a0a2.h"
#include "../inc/flash_if.h"
#include <string.h>

// Flash locations (adjust within 64KB program flash)
// The last 512B split into 4×128B
#define FLASH_A0_LOW  (0x0000F800u)
#define FLASH_A0_HI   (0x0000F880u)
#define FLASH_A2_LOW  (0x0000F900u)
#define FLASH_A2_HI   (0x0000F980u)

eep_page_t g_a0_low, g_a0_hi, g_a2_low, g_a2_hi;

void eep_pages_init_from_flash(void) {
  flash_read(FLASH_A0_LOW, (uint8_t*)&g_a0_low, sizeof(eep_page_t));
  flash_read(FLASH_A0_HI,  (uint8_t*)&g_a0_low, sizeof(eep_page_t));
  flash_read(FLASH_A2_LOW, (uint8_t*)&g_a0_low, sizeof(eep_page_t));
  flash_read(FLASH_A2_HI,  (uint8_t*)&g_a0_low, sizeof(eep_page_t));
}

void eep_pages_commit_to_flash(void) {
  flash_page_erase(FLASH_A0_LOW);
  flash_write(FLASH_A0_LOW, (uint8_t*)&g_a0_low, sizeof(eep_page_t));
  flash_write(FLASH_A0_HI,  (uint8_t*)&g_a0_low, sizeof(eep_page_t));
  flash_write(FLASH_A2_LOW, (uint8_t*)&g_a0_low, sizeof(eep_page_t));
  flash_write(FLASH_A2_HI,  (uint8_t*)&g_a0_low, sizeof(eep_page_t));
}

#ifdef __cplusplus
}
#endif // __cplusplus
