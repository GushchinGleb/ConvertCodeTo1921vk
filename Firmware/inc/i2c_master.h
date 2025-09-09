#pragma once
#include <stdint.h>
#include <stdbool.h>

bool i2cm_init(uint32_t pclk_hz, uint32_t scl_hz);
bool i2cm_write(uint8_t addr7, const uint8_t* data, uint32_t len);
bool i2cm_write_reg(uint8_t addr7, uint8_t reg, uint8_t val);
bool i2cm_read_reg(uint8_t addr7, uint8_t reg, uint8_t* val);
