#pragma once
#include <stdint.h>

// Register map (from your original firmware)
#define MASC_CHIPID      0x00
#define MASC_REVID       0x01
#define MASC_RESET_REG   0x02
// ... (keep all as in the original)
#define MASC_ADC_OUT_MSB 0x65
#define MASC_ADC_OUT_LSB 0x66

#define MASC_37029_CHIPID_VALUE 0x87
#define MASC_37028_CHIPID_VALUE 0x8D
