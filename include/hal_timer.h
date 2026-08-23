#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include <stdint.h>

typedef void (*hal_timer_callback_t)(void);

/* Configures a hardware timer to call `callback` every `period_us`. */
void HAL_Timer_Init(uint32_t period_us, hal_timer_callback_t callback);

#endif
