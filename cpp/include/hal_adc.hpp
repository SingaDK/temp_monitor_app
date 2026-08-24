#ifndef HAL_ADC_HPP
#define HAL_ADC_HPP

#include <cstdint>

class Adc
{
public:
    uint16_t Read() const;
    void SetValue(uint16_t raw_value);

private:
    uint16_t m_value = 0;
};

#endif