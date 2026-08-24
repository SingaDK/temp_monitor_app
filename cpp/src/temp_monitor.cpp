#include "temp_monitor.hpp"

TempState TempMonitor::Evaluate(int16_t tenths_degc) const
{
    if (tenths_degc >= CRITICAL_HIGH_TENTHS || tenths_degc < CRITICAL_LOW_TENTHS)
    {
        return TempState::Critical;
    }
    if (tenths_degc >= WARNING_TENTHS)
    {
        return TempState::Warning;
    }
    return TempState::Ok;
}
