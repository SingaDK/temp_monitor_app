#ifndef TEMPERATURE_MONITOR_H
#define TEMPERATURE_MONITOR_H

#include <stdint.h>

typedef enum {
    TEMP_STATE_OK,
    TEMP_STATE_WARNING,
    TEMP_STATE_CRITICAL
} temp_state_t;

temp_state_t TemperatureMonitor_Evaluate(int16_t tenths_degc);

#endif
