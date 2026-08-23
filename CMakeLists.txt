cmake_minimum_required(VERSION 3.14)
project(temperature_monitor C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(temperature_monitor
    src/main.c
    src/hal_i2c_mock.c
    src/eeprom_config.c
)

target_include_directories(temperature_monitor PRIVATE include)
target_compile_options(temperature_monitor PRIVATE -Wall -Wextra)

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
