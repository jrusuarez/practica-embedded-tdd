#include "CppUTest/TestHarness.h"
#include "Temperature/Temperature.h"

#include "mocks/ADCMock.h"

TEST_GROUP(TemperatureTestGroup)
{
    void setup() {
        ADCMockInit();
    }

    void teardown() {
    }
};

TEST(TemperatureTestGroup, 0Degrees)
{
    FAIL("Test not implemented yet");
}

TEST(TemperatureTestGroup, 25Degrees)
{
    FAIL("Test not implemented yet");
}

TEST(TemperatureTestGroup, 100Degrees)
{
    FAIL("Test not implemented yet");
}
