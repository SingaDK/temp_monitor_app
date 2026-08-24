#ifndef HAL_GPIO_HPP
#define HAL_GPIO_HPP

enum class LedId
{
    Green,
    Yellow,
    Red
};

class Gpio
{
public:
    void WriteLed(LedId led, bool on);
};

#endif
