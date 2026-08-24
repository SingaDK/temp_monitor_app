#include "hal_gpio.hpp"
#include <iostream>

const char *LedName(LedId led)
{
    switch (led)
    {
    case LedId::Green:
        return "GREEN";
    case LedId::Yellow:
        return "YELLOW";
    case LedId::Red:
        return "RED";
    }
    return "?";
}

void Gpio::WriteLed(LedId led, bool on)
{
    std::cout << "[GPIO] LED " << LedName(led) << " -> " << (on ? "ON" : "off") << "\n";
}
