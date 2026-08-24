#include "hal_adc.h"

static uint16_t s_mock_value;

uint16_t HAL_ADC_Read(void)
{
    return s_mock_value;
}

void HAL_ADC_SetMockValue(uint16_t raw_value)
{
    s_mock_value = raw_value;
}