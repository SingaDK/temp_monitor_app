#include "temp_sensor.hpp"

// Rev-A: 1 degC / digit -> tenths = raw * 10
int16_t RevASensor::ToTenthsDegC(uint16_t raw) const
{
    return static_cast<int16_t>(raw * 10U);
}

// Rev-B: 0.1 degC / digit -> raw is already expressed in tenths
int16_t RevBSensor::ToTenthsDegC(uint16_t raw) const
{
    return static_cast<int16_t>(raw);
}

std::unique_ptr<TemperatureSensor> MakeSensorStrategy(uint8_t hw_revision)
{
    if (hw_revision == 1U) {
        return std::make_unique<RevBSensor>();
    }
    return std::make_unique<RevASensor>();
}
