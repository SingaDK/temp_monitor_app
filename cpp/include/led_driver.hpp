#ifndef LED_DRIVER_HPP
#define LED_DRIVER_HPP

#include "hal_gpio.hpp"
#include "temp_monitor.hpp"

class LedDriver {
public:
    explicit LedDriver(Gpio &gpio) : m_gpio(gpio) {}

    void SetState(TempState state);

private:
    Gpio &m_gpio;
};

#endif
