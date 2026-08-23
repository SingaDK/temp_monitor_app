#ifndef TIMER_ISR_H
#define TIMER_ISR_H

#include <stdint.h>

void TimerISR_Handler(void);

uint16_t TimerISR_GetLatestSample(void);

#endif
