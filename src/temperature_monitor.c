#include "temperature_monitor.h"

#define CRITICAL_HIGH_TENTHS 1050 /* >= 105.0 degC */
#define CRITICAL_LOW_TENTHS 50    /* <    5.0 degC */
#define WARNING_TENTHS 850        /* >=  85.0 degC */

temp_state_t TemperatureMonitor_Evaluate(int16_t tenths_degc)
{
    if (tenths_degc >= CRITICAL_HIGH_TENTHS || tenths_degc < CRITICAL_LOW_TENTHS)
    {
        return TEMP_STATE_CRITICAL;
    }
    if (tenths_degc >= WARNING_TENTHS)
    {
        return TEMP_STATE_WARNING;
    }
    return TEMP_STATE_OK;
}
