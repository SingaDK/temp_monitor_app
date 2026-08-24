#include "hal_i2c.hpp"
#include <cstring>

const std::array<uint8_t, 9> I2c::s_contents = {
    0x01, 'A', 'B', 'C', '1', '2', '3', '4', '\0'};

bool I2c::Read(uint8_t device_addr, uint8_t reg, uint8_t *buf, size_t len) const
{
    (void)device_addr;

    if (static_cast<size_t>(reg) + len > s_contents.size())
    {
        return false;
    }
    std::memcpy(buf, &s_contents[reg], len);

    return true;
}