#include "hal_adc.hpp"

uint16_t Adc::Read() const
{
    return m_value;
}

void Adc::SetValue(uint16_t raw_value)
{
    m_value = raw_value;
}
