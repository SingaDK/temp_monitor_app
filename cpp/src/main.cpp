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

class TimerIsr
{
public:
    void Handler(const Adc &adc) { m_latest = adc.Read(); }
    uint16_t Latest() const { return m_latest; }

private:
    volatile uint16_t m_latest = 0;
};

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
    TimerIsr timerIsr;

    timer.Init(100);

    const uint16_t raw_value = 20;

    adc.SetValue(raw_value);

    timerIsr.Handler(adc);

    int16_t tenths = sensor->ToTenthsDegC(timerIsr.Latest());
    TempState state = monitor.Evaluate(tenths);

    std::cout << "raw_value=" << raw_value << "  temp=" << (tenths / 10) << "." << (tenths % 10)
              << " C  state=" << StateName(state) << "\n";
    led.SetState(state);
    std::cout << "\n";

    return 0;
}
