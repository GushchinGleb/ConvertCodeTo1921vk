#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
#ifndef _EEPROM_A0A2_H
#define _EEPROM_A0A2_H
#include <stdint.h>

void a0a2_pages_init_from_flash(void);
void a0a2_pages_commit_to_flash(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _EEPROM_A0A2_H
