#pragma once
#include <stdint.h>

typedef struct __attribute__((packed)) {
  uint8_t bytes[128];
} eep_page_t;

void eep_pages_init_from_flash(void);
void eep_pages_commit_to_flash(void);

extern eep_page_t g_a0_low, g_a0_hi, g_a2_low, g_a2_hi;
