#include "eeprom_config.h"
#include "hal_i2c.h"

#define EEPROM_I2C_ADDR   0x10U
#define REG_HW_REVISION   0x00U
#define REG_SERIAL_NUMBER 0x01U

void EepromConfig_Load(eeprom_config_t *config)
{
    HAL_I2C_Read(EEPROM_I2C_ADDR, REG_HW_REVISION, &config->hw_revision, 1);
    HAL_I2C_Read(EEPROM_I2C_ADDR, REG_SERIAL_NUMBER,
                 (uint8_t *)config->serial_number, sizeof(config->serial_number));
}
