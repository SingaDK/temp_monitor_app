include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)

set(FAKEIT_HEADER ${CMAKE_CURRENT_BINARY_DIR}/fakeit.hpp)
if(NOT EXISTS ${FAKEIT_HEADER})
    file(DOWNLOAD
        https://raw.githubusercontent.com/eranpeer/FakeIt/master/single_header/standalone/fakeit.hpp
        ${FAKEIT_HEADER})
endif()
add_library(fakeit INTERFACE)
target_include_directories(fakeit INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

add_executable(unit_tests
    test_temp_monitor.cpp
    ../src/sensor_strategy.c
    ../src/temperature_monitor.c
    ../src/eeprom_config.c
    ../src/hal_i2c_mock.c
)

target_include_directories(unit_tests PRIVATE ../include)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain fakeit)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(unit_tests)
