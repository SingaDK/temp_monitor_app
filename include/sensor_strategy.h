#ifndef SENSOR_STRATEGY_H
#define SENSOR_STRATEGY_H

#include <stdint.h>

/* Converts a raw ADC reading to tenths of a degree Celsius. */
typedef int16_t (*sensor_raw_to_tenths_fn)(uint16_t raw);

/* Picks the conversion matching the sensor fitted for this hw_revision. */
sensor_raw_to_tenths_fn SensorStrategy_Select(uint8_t hw_revision);

#endif