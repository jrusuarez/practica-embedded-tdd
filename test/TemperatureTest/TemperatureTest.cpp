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
    TemperatureTask();
    ADCMockTriggerADCValue(0);
    CHECK_EQUAL(0, getTemperatureInCx10());
}

TEST(TemperatureTestGroup, 25Degrees)
{
    TemperatureTask();
    ADCMockTriggerADCValue(ADC_MAX_VALUE / 4);
    CHECK_EQUAL(250, getTemperatureInCx10());
}

TEST(TemperatureTestGroup, 100Degrees)
{
    TemperatureTask();
    ADCMockTriggerADCValue(ADC_MAX_VALUE);
    CHECK_EQUAL(1000, getTemperatureInCx10());
}
