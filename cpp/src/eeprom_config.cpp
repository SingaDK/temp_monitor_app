#include "eeprom_config.hpp"

namespace
{
    constexpr uint8_t EEPROM_I2C_ADDR = 0x50;
    constexpr uint8_t REG_HW_REVISION = 0x00;
    constexpr uint8_t REG_SERIAL_NUMBER = 0x01;
    constexpr size_t SERIAL_LEN = 8;
} // namespace desicion - Compile time constant

EepromConfig::EepromConfig(const I2c &i2c)
{
    i2c.Read(EEPROM_I2C_ADDR, REG_HW_REVISION, &m_hw_revision, 1);

    uint8_t buf[SERIAL_LEN] = {};
    i2c.Read(EEPROM_I2C_ADDR, REG_SERIAL_NUMBER, buf, SERIAL_LEN);
    m_serial_number = std::string(reinterpret_cast<char *>(buf));
}
