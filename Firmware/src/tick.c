#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
#include "K1921VK035.h"
#include <stdint.h>
#include "../inc/tick.h"
#include "../inc/sfp28.h"

// Configure a general-purpose timer to 1 kHz and roll flags.

uint8_t Time_flags;
static uint16_t s_ms = 0;

void tick_init(uint32_t sysclk_hz){
	const uint32_t timer_freq = 1000u; // 1 kHz
	const uint32_t delay_tiks = sysclk_hz / timer_freq - 1;

	TMR0->VALUE = delay_tiks; // [page 56]
	TMR0->LOAD = delay_tiks;  // [page 56]

  TMR0->CTRL = 1 << TMR_CTRL_INTEN_Pos | 1 << TMR_CTRL_ON_Pos; // [page 56], page[309]
	
	return;
}

void TMR0_IRQHandler(void) { // startup_K1921VK035.s:100
  s_ms++;
  if(!(s_ms % 100)) {
		Time_flags |= TIME_100MS_FLAG;
	}
  if(!(s_ms % 500)) {
		Time_flags |= TIME_500MS_FLAG;
	}
  if(!(s_ms % 1000)) {
		Time_flags |= TIME_1SEC_FLAG;
		s_ms=0;
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus
