#include <stdint.h>
#include "board.h"
#include "sfp28.h"
#include "tick.h"
#include "flash_if.h"
#include "i2c_master.h"
#include "i2c_slave.h"
#include "eeprom_a0a2.h"
#include "masc37029.h"

static void gpio_init(void){
  // Configure VK035 GPIO dir, pull, altfunc:
  // - assign I2C1 pins for SFP slave (SCL/SDA)
  // - assign I2C0 pins for MASC master (SCL/SDA)
  // - TX_DISABLE/RS pins outputs; LOS/TX_FAULT inputs
  // GPIO register details are in Appendix A.2. (dir, alt func, pull). :contentReference[oaicite:32]{index=32}
}

int main(void){
  // 1) Clocks
  select_sysclk_osi();                 // safe
  clock_init_100mhz_from_hse(8000000); // or keep OSI if no crystal

  // 2) GPIO and peripherals
  gpio_init();
  tick_init(100000000u);
  flash_init();
  eep_pages_init_from_flash();

  // 3) I2C: master to MASC; slave to host
  i2cm_init(/*pclk*/100000000u, /*scl*/100000u);
  i2cs_init(I2C_ADDR_A0); // We’ll handle 0x50 & 0x51 in ISR by aliasing or instantiate a second slave if HW supports dual address.

  // 4) Probe MASC
  uint8_t id=0;
  if(masc_read_id(&id)){
    // compare against 0x87/0x8D
  }

  // 5) Main loop
  for(;;){
    uint8_t f = g_time_flags; g_time_flags = 0;

    if(f & TIME_100MS_FLAG){
      // poll LOS/TX_FAULT, update A2 Stat_Control bits, etc.
    }
    if(f & TIME_1SEC_FLAG){
      // optional periodic commits or MASC health checks
    }
  }
}
