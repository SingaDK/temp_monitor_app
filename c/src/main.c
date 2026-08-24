#include <stdint.h>
#include <stdio.h>

#include "eeprom_config.h"
#include "hal_adc.h"
#include "led_driver.h"
#include "sensor_strategy.h"
#include "temperature_monitor.h"
#include "timer_isr.h"

static const char *StateName(temp_state_t state)
{
    switch (state)
    {
    case TEMP_STATE_OK:
        return "OK";
    case TEMP_STATE_WARNING:
        return "WARNING";
    case TEMP_STATE_CRITICAL:
        return "CRITICAL";
    default:
        return "?";
    }
}

int main(void)
{
    eeprom_config_t config;
    EepromConfig_Load(&config);

    sensor_raw_to_tenths_fn raw_to_tenths = SensorStrategy_Select(config.hw_revision);

    printf("HW revision: %s, serial: %s\n\n",
           config.hw_revision == 1U ? "Rev-B" : "Rev-A", config.serial_number);

    /* Raw ADC counts (Rev-B, 0.1 degC/digit) sweeping through critical-low,
     * OK, warning and critical-high readings. */
    uint16_t raw_vaue = 20;

    HAL_ADC_SetMockValue(raw_vaue);

    /* Fires every 100us on real hardware. */
    TimerISR_Handler(); /* simulates one 100us timer tick */

    int16_t tenths = raw_to_tenths(TimerISR_GetLatestSample());
    temp_state_t state = TemperatureMonitor_Evaluate(tenths);

    printf("raw=%u  temp=%d.%01d C  state=%s\n",
           raw_vaue, tenths / 10, tenths % 10, StateName(state));
    LedDriver_SetState(state);
    printf("\n");

    return 0;
}
