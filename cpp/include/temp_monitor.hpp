#ifndef TEMPERATURE_MONITOR_HPP
#define TEMPERATURE_MONITOR_HPP

#include <cstdint>

enum class TempState { Ok, Warning, Critical };

class TempMonitor {
public:
    TempState Evaluate(int16_t tenths_degc) const;

private:
    static constexpr int16_t CRITICAL_HIGH_TENTHS = 1050;  // >= 105.0 degC
    static constexpr int16_t CRITICAL_LOW_TENTHS = 50;     // <    5.0 degC
    static constexpr int16_t WARNING_TENTHS = 850;         // >=  85.0 degC
};

#endif
