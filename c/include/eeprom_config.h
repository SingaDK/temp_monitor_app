#ifndef EEPROM_CONFIG_H
#define EEPROM_CONFIG_H

#include <stdint.h>

typedef struct {
    uint8_t hw_revision;    /* 0 = Rev-A, 1 = Rev-B */
    char serial_number[8];  /* e.g. "ABC1234" */
} eeprom_config_t;

void EepromConfig_Load(eeprom_config_t *config);

#endif