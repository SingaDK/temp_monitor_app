#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include <cstdint>
#include <memory>

class TemperatureSensor
{
public:
    virtual ~TemperatureSensor() = default;
    virtual int16_t ToTenthsDegC(uint16_t raw) const = 0;
};

class RevASensor : public TemperatureSensor
{
public:
    int16_t ToTenthsDegC(uint16_t raw) const override;
};

class RevBSensor : public TemperatureSensor
{
public:
    int16_t ToTenthsDegC(uint16_t raw) const override;
};

// Use unique pointer to pick concrete strategy
std::unique_ptr<TemperatureSensor> MakeSensorStrategy(uint8_t hw_revision);

#endif
