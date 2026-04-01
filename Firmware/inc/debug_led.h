#ifndef _DEBUG_LED_H
#define _DEBUG_LED_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void debug_led_init(void);

void debug_led_on(void);

void debug_led_off(void);

void debug_led_toggle(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _DEBUG_LED_H
