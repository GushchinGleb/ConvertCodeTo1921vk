#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "K1921VK035.h"

#include "../inc/debug_led.h"

// Pin LED (A8) OUT
#define GPIO_LEDS GPIOA
#define PIN_LED_MASK (1 << 8)  // from the maket board      (RST_TX)
#define PIB_DBG_MASK (1 << 13) // from the production board (RX_LOS)
#define PIN_LED_MASK_2 (0x3 << 16) // from the maket board      (RST_TX)
#define PIB_DBG_MASK_2 (0x3 << 26) // from the production board (RX_LOS)


void debug_led_init(void) {
  // GPIO_LEDS->PULLMODE &= ~(PIN_LED_MASK_2 | PIB_DBG_MASK_2); // no pull [page 212]
  GPIO_LEDS->DENSET = PIN_LED_MASK | PIB_DBG_MASK; // OUT enable [page 210]
  GPIO_LEDS->OUTENSET = PIN_LED_MASK | PIB_DBG_MASK; // [page 51], [page 9]
}

void debug_led_on() {
  GPIO_LEDS->DATAOUTSET = PIN_LED_MASK | PIB_DBG_MASK;
}

void debug_led_off() {
  GPIO_LEDS->DATAOUTCLR = PIN_LED_MASK | PIB_DBG_MASK;
}

void debug_led_toggle() {
  GPIO_LEDS->DATAOUTTGL = PIN_LED_MASK | PIB_DBG_MASK;
}

#ifdef __cplusplus
}
#endif // __cplusplus
