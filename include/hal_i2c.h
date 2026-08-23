#ifndef HAL_I2C_H
#define HAL_I2C_H

#include <stdint.h>
#include <stddef.h>

int HAL_I2C_Read(uint8_t device_addr, uint8_t reg, uint8_t *buf, size_t len);

#endif