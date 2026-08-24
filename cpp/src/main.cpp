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
#include "temp_sensor.hpp"

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
    std::cout << "HW revision: " << (config.HwRevision() == 1 ? "Rev-B" : "Rev-A")
              << ", serial: " << config.SerialNumber() << "\n\n";

    std::unique_ptr<TemperatureSensor> sensor = MakeSensorStrategy(config.HwRevision());

    Adc adc;
    Gpio gpio;
    Timer timer;
    TempMonitor monitor;
    LedDriver led(gpio);

    timer.Init(100); // configure the 100us sampling period (symbolic on PC demo)

    const uint16_t raw_value = 20;

    adc.SetValue(raw_value);

    TimerIsrHandler(adc); // simulates one 100us timer tick

    int16_t tenths = sensor->ToTenthsDegC(s_latest_sample);
    TempState state = monitor.Evaluate(tenths);

    std::cout << "raw_value=" << raw_value << "  temp=" << (tenths / 10) << "." << (tenths % 10)
              << " C  state=" << StateName(state) << "\n";
    led.SetState(state);
    std::cout << "\n";

    return 0;
}
