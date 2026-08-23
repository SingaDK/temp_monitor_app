#ifndef HAL_GPIO_H
#define HAL_GPIO_H

typedef enum
{
    GPIO_LED_GREEN,
    GPIO_LED_YELLOW,
    GPIO_LED_RED
} gpio_led_t;

void HAL_GPIO_WriteLed(gpio_led_t led, int on);

#endif
