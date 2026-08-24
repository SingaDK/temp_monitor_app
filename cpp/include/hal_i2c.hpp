#ifndef HAL_I2C_HPP
#define HAL_I2C_HPP

#include <cstdint>
#include <cstddef>
#include <array>


class I2c {
public:
    bool Read(uint8_t device_addr, uint8_t reg, uint8_t *buf, size_t len) const;

private:
    // reg 0: hw_revision, reg 1: serial number placeholder
    static const std::array<uint8_t, 9> s_contents;
};


#endif