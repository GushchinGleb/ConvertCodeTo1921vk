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
  uint32_t delay_tiks = sysclk_hz / timer_freq - 1;
  
  RCU->PCLKCFG |= RCU_PCLKCFG_TMR0EN_Msk | RCU_PCLKCFG_TMR1EN_Msk;
  RCU->PRSTCFG |= RCU_PRSTCFG_TMR0EN_Msk | RCU_PRSTCFG_TMR1EN_Msk;

  TMR0->LOAD = delay_tiks;  // [page 56]
  TMR0->VALUE = 0L;         // [page 56]

  NVIC_SetPriority(TMR0_IRQn, (1UL << __NVIC_PRIO_BITS) + 10UL); // internal scheduler clock. Low priority.
  NVIC_EnableIRQ(TMR0_IRQn);
  
  TMR0->CTRL = TMR_CTRL_ON_Msk | TMR_CTRL_INTEN_Msk;
  TMR0->INTSTATUS = TMR_INTSTATUS_INT_Msk;
  
  const uint32_t soft_i2c_freq = 100000 * 4; // 400 kHz
  delay_tiks = sysclk_hz / soft_i2c_freq - 1;

  TMR1->LOAD = delay_tiks;  // [page 56]
  TMR1->VALUE = 0L;         // [page 56]
  
  NVIC_SetPriority(TMR1_IRQn, (1UL << __NVIC_PRIO_BITS) + 5UL); // I2C clock. Midle priority.
  NVIC_EnableIRQ(TMR1_IRQn);
  
  TMR1->CTRL = TMR_CTRL_ON_Msk | TMR_CTRL_INTEN_Msk;
  TMR1->INTSTATUS = TMR_INTSTATUS_INT_Msk;
  
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
  
  TMR0->INTSTATUS = TMR_INTSTATUS_INT_Msk;
}

// TMR1_IRQHandler is realised in soft_i2c.c

#ifdef __cplusplus
}
#endif // __cplusplus
