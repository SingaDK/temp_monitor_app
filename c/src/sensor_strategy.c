#include "sensor_strategy.h"

/* Rev-A: 1 degC / digit -> tenths = raw * 10 */
static int16_t ConvertRevA(uint16_t raw)
{
    return (int16_t)(raw * 10U);
}

/* Rev-B: 0.1 degC / digit -> raw is already expressed in tenths */
static int16_t ConvertRevB(uint16_t raw)
{
    return (int16_t)raw;
}

sensor_raw_to_tenths_fn SensorStrategy_Select(uint8_t hw_revision)
{
    return (hw_revision == 1U) ? ConvertRevB : ConvertRevA;
}
