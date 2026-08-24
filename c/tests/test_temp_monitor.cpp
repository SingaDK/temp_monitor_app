#include <catch2/catch_test_macros.hpp>

extern "C"
{
#include "temperature_monitor.h"
}

TEST_CASE("Temperature state follows the OK/WARNING/CRITICAL thresholds")
{
    CHECK(TemperatureMonitor_Evaluate(500) == TEMP_STATE_OK);        // 50.0 C
    CHECK(TemperatureMonitor_Evaluate(849) == TEMP_STATE_OK);        // 84.9 C
    CHECK(TemperatureMonitor_Evaluate(850) == TEMP_STATE_WARNING);   // 85.0 C
    CHECK(TemperatureMonitor_Evaluate(1049) == TEMP_STATE_WARNING);  // 104.9 C
    CHECK(TemperatureMonitor_Evaluate(1050) == TEMP_STATE_CRITICAL); // 105.0 C
    CHECK(TemperatureMonitor_Evaluate(50) == TEMP_STATE_OK);         // 5.0 C
    CHECK(TemperatureMonitor_Evaluate(49) == TEMP_STATE_CRITICAL);   // 4.9 C
}
