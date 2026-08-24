#include "hal_timer.h"

static hal_timer_callback_t s_callback;

void HAL_Timer_Init(uint32_t period_us, hal_timer_callback_t callback)
{
    (void)period_us;
    s_callback = callback;
}
