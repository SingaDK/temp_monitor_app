#include <stdio.h>

#include "eeprom_config.h"

int main(void)
{
    eeprom_config_t config;
    EepromConfig_Load(&config);
    printf("Temperature Monitor\n");
    return 0;
}
