#ifndef EEPROM_CONFIG_HPP
#define EEPROM_CONFIG_HPP

#include <cstdint>
#include <string>
#include "hal_i2c.hpp"

class EepromConfig {
public:
    explicit EepromConfig(const I2c &i2c);

    uint8_t HwRevision() const { return m_hw_revision; }
    const std::string &SerialNumber() const { return m_serial_number; }

private:
    uint8_t m_hw_revision = 0;
    std::string m_serial_number;
};

#endif