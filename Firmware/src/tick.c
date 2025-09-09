#include "tick.h"
#include "sfp28.h"

// Configure a general-purpose timer to 1 kHz and roll flags.

volatile uint8_t g_time_flags = 0;
static uint16_t s_ms = 0;

void tick_init(uint32_t sysclk_hz){
  // Program Timer: prescaler and ARR for 1 kHz; enable IRQ.
  // VK035 timer regs are in Appendix A.12 (not shown here).
}

void TIMx_IRQHandler(void){
  // Clear timer flag
  s_ms++;
  if((s_ms % 100) == 0) g_time_flags |= TIME_100MS_FLAG;
  if((s_ms % 500) == 0) g_time_flags |= TIME_500MS_FLAG;
  if(s_ms == 1000){ g_time_flags |= TIME_1SEC_FLAG; s_ms=0; }
}
