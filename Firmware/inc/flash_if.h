#pragma once
#include <stdint.h>
#include <stdbool.h>

bool flash_init(void);
bool flash_page_erase(uint32_t addr);
bool flash_read128(uint32_t addr, uint32_t* out32x2);
bool flash_write128(uint32_t addr, const uint32_t* in32x2);
