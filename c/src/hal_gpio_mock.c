#include "hal_gpio.h"
#include <stdio.h>

static const char *LedName(gpio_led_t led)
{
    switch (led)
    {
    case GPIO_LED_GREEN:
        return "GREEN";
    case GPIO_LED_YELLOW:
        return "YELLOW";
    case GPIO_LED_RED:
        return "RED";
    default:
        return "?";
    }
}

void HAL_GPIO_WriteLed(gpio_led_t led, int on)
{
    printf("[GPIO] LED %-6s -> %s\n", LedName(led), on ? "ON" : "off");
}
