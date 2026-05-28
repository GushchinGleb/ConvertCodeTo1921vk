#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
  
#include "K1921VK035.h"
#include <stdint.h>
#include "../inc/tick.h"
#include "../inc/sfp28.h"

// Configure a general-purpose timer to 1 kHz and roll flags.

uint8_t Time_flags;
static uint8_t Timer10ms_count = 0;		// Counter for 10ms timer
static uint8_t Timer100ms_count = 0;		// Counter for 100ms timer
static uint32_t us_tick_num = 0;

void tick_init(uint32_t sysclk_hz){
  const uint32_t timer_freq = 100u; // 100 Hz
  uint32_t delay_tiks = sysclk_hz / timer_freq - 1;
  
  RCU->PCLKCFG |= RCU_PCLKCFG_TMR0EN_Msk | RCU_PCLKCFG_TMR1EN_Msk;
  RCU->PRSTCFG |= RCU_PRSTCFG_TMR0EN_Msk | RCU_PRSTCFG_TMR1EN_Msk;

  TMR0->LOAD = delay_tiks;  // [page 56]
  TMR0->VALUE = 0L;         // [page 56]

  NVIC_SetPriority(TMR0_IRQn, (1UL << __NVIC_PRIO_BITS) + 10UL); // internal scheduler clock. Low priority.
  NVIC_EnableIRQ(TMR0_IRQn);
  
  TMR0->CTRL = TMR_CTRL_ON_Msk | TMR_CTRL_INTEN_Msk;
  TMR0->INTSTATUS = TMR_INTSTATUS_INT_Msk;
  
	// Init timer 1 for us delay function
	// We don't use interrupt for this timer
	// Timer will be load and start in delay function
	us_tick_num = sysclk_hz / 1000000 - 1;

  TMR1->CTRL = 0;	//stop timer
  TMR1->INTSTATUS = TMR_INTSTATUS_INT_Msk;	//Clear int
  
  return;
}

void TMR0_IRQHandler(void) { // startup_K1921VK035.s:100
	//Inc counter
	Timer10ms_count++;
	if(Timer10ms_count >= 10) {
		Time_flags |= TIME_100MS_FLAG;
		Timer10ms_count = 0;
		Timer100ms_count++;
	}
	if(Timer100ms_count == 5)
		Time_flags |= TIME_500MS_FLAG;
	if(Timer100ms_count >= 10) {
		Time_flags |= TIME_500MS_FLAG;
		Time_flags |= TIME_1SEC_FLAG;
		Timer100ms_count = 0;
	}
  
  TMR0->INTSTATUS = TMR_INTSTATUS_INT_Msk;
}

// TMR1 is used as delay counter
void delay_us(uint32_t us_count) {
  uint32_t Temp_u32 = us_count * us_tick_num;
  TMR1->LOAD = Temp_u32;  // [page 56]
	TMR1->VALUE = Temp_u32;         // [page 56]
  TMR1->INTSTATUS = TMR_INTSTATUS_INT_Msk;
  TMR1->CTRL = TMR_CTRL_ON_Msk | TMR_CTRL_INTEN_Msk;
	while(TMR1->INTSTATUS_bit.INT == 0);
  TMR1->CTRL = 0;	//stop timer
  TMR1->INTSTATUS = TMR_INTSTATUS_INT_Msk;	//Clear int
}

// TMR1_IRQHandler is realised in soft_i2c.c

#ifdef __cplusplus
}
#endif // __cplusplus
