#pragma once
#include <stdint.h>
#include <stdbool.h>

void i2cs_init(uint8_t addr7);
void i2cs_isr(void);      // call from IRQ handler
