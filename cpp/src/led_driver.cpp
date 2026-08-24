#include "led_driver.hpp"

void LedDriver::SetState(TempState state)
{
    m_gpio.WriteLed(LedId::Green, state == TempState::Ok);
    m_gpio.WriteLed(LedId::Yellow, state == TempState::Warning);
    m_gpio.WriteLed(LedId::Red, state == TempState::Critical);
}
