#include <catch2/catch_test_macros.hpp>
#include <fakeit.hpp>

using namespace fakeit;

class IExample
{
public:
    virtual ~IExample() = default;
    virtual int GetValue() = 0;
};

TEST_CASE("dummy assert - placeholder")
{
    REQUIRE(1 + 1 == 2);
}
