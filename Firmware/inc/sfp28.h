#pragma once
#include <stdint.h>

// Software / password constants (ported 1:1)
#define SFP28_MODULE_SW_ID  0xA3
#define SOFTWARE_VERSION    0x0001
#define PASS_CONST_B0       0xA3
#define PASS_CONST_B1       0x25
#define PASS_CONST_B2       0xA0
#define PASS_CONST_B3       0x6F

// Time flags
#define TIME_100MS_FLAG (1u << 0)
#define TIME_500MS_FLAG (1u << 1)
#define TIME_1SEC_FLAG  (1u << 2)

extern volatile uint8_t g_time_flags;
