#include <array>
#include <iostream>
#include <memory>

#include "eeprom_config.hpp"
#include "hal_adc.hpp"
#include "hal_gpio.hpp"
#include "hal_i2c.hpp"
#include "hal_timer.hpp"
#include "led_driver.hpp"
#include "temp_monitor.hpp"

volatile uint16_t s_latest_sample = 0;

void TimerIsrHandler(const Adc &adc)
{
    s_latest_sample = adc.Read();
}

const char *StateName(TempState state)
{
    switch (state)
    {
    case TempState::Ok:
        return "OK";
    case TempState::Warning:
        return "WARNING";
    case TempState::Critical:
        return "CRITICAL";
    }
    return "?";
}

int main()
{
    I2c i2c;
    EepromConfig config(i2c);

    return 0;
}
