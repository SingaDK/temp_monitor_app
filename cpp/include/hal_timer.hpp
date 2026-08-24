#ifndef HAL_TIMER_HPP
#define HAL_TIMER_HPP

#include <cstdint>

class Timer
{
public:
    void Init(uint32_t period_us);
};

#endif