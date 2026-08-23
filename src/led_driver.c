#include "led_driver.h"
#include "hal_gpio.h"

void LedDriver_SetState(temp_state_t state)
{
    HAL_GPIO_WriteLed(GPIO_LED_GREEN, state == TEMP_STATE_OK);
    HAL_GPIO_WriteLed(GPIO_LED_YELLOW, state == TEMP_STATE_WARNING);
    HAL_GPIO_WriteLed(GPIO_LED_RED, state == TEMP_STATE_CRITICAL);
}
