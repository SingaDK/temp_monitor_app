#ifndef HAL_ADC_H
#define HAL_ADC_H

#include <stdint.h>

uint16_t HAL_ADC_Read(void);

void HAL_ADC_SetMockValue(uint16_t raw_value);

#endif