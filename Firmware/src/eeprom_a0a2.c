#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/eeprom_a0a2.h"
#include "../inc/flash_if.h"
#include "../inc/sfp28.h"
#include <string.h>

// Flash locations (adjust within 64KB program flash)
// The last 1KB is for user data
#define FLASH_PAGE  (0x0000FC00)
#define FLASH_A0    (FLASH_PAGE + sizeof(A0_Page.var))
#define FLASH_A2    (FLASH_A0   + sizeof(A2_Page.var))
#define FLASH_A2_UP (FLASH_A2   + sizeof(A2Up_Page.var))

A0_Page_t A0_Page;
A2_Page_t A2_Page;
A2Up_Page_t A2Up_Page;

void a0a2_pages_init_from_flash(void) {
  flash_read(FLASH_A0,    (uint8_t*)&A0_Page.var,   sizeof(A0_Page.var));
  flash_read(FLASH_A2,    (uint8_t*)&A2_Page.var,   sizeof(A2_Page.var));
  flash_read(FLASH_A2_UP, (uint8_t*)&A2Up_Page.var, sizeof(A2Up_Page.var));
}

void a0a2_pages_commit_to_flash(void) {
  flash_page_erase(FLASH_PAGE);
  flash_write(FLASH_A0,    (uint8_t*)&A0_Page.var,   sizeof(A0_Page.var));
  flash_write(FLASH_A2,    (uint8_t*)&A2_Page.var,   sizeof(A2_Page.var));
  flash_write(FLASH_A2_UP, (uint8_t*)&A2Up_Page.var, sizeof(A2Up_Page.var));
}

#ifdef __cplusplus
}
#endif // __cplusplus
