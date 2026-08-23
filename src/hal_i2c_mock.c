#include "hal_i2c.h"
#include <string.h>

/* Example EEPROM's contents. */
static const uint8_t s_mock_eeprom[] = {
    0x01,
    'A', 'B', 'C', '1', '2', '3', '4', '\0'
};

int HAL_I2C_Read(uint8_t device_addr, uint8_t reg, uint8_t *buf, size_t len)
{
    (void)device_addr;

    if ((size_t)reg + len > sizeof(s_mock_eeprom)) {
        return -1;
    }

    memcpy(buf, &s_mock_eeprom[reg], len);
    return 0;
}