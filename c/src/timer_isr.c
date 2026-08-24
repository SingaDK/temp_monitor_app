#include "timer_isr.h"
#include "hal_adc.h"

static volatile uint16_t s_latest_sample;

void TimerISR_Handler(void)
{
    s_latest_sample = HAL_ADC_Read();
}

uint16_t TimerISR_GetLatestSample(void)
{
    return s_latest_sample;
}
