#ifndef _TICK_H
#define _TICK_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

/**
 * @brief Run the timer on timer0 on 1kHz. Enable interupts.
 * @param sysclk_hz core frequency
 */
void tick_init(uint32_t sysclk_hz);

#ifdef __cplusplus
}
#endif // __cplusplus
	
#endif // _TICK_H
