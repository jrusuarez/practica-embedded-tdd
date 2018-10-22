#include "CppUTest/TestHarness.h"
#include "Thermostat/Thermostat.h"
#include "mocks/ActuatorMock.h"
#include "mocks/TemperatureMock.h"

TEST_GROUP(ThermostatTestGroup)
{
    void setup() {
        ActuatorMockInit();
    }

    void teardown() {
    }
};

TEST(ThermostatTestGroup, TurnOnIfMeasuredTempBelowDesiredTempMinusHystThreshold)
{
    FAIL("Test not implemented yet");
}

TEST(ThermostatTestGroup, StayOnIfMeasuredTempBelowDesiredTempPlusHystThreshold)
{
    FAIL("Test not implemented yet");
}

TEST(ThermostatTestGroup, TurnOffWhenAlreadyOnAndMeasuredTempAboveDesiredTempPlusHystThreshold)
{
    FAIL("Test not implemented yet");
}

TEST(ThermostatTestGroup, StayOffWhenMeasuredTempAboveDesiredTempMinusHystThreshold)
{
    FAIL("Test not implemented yet");
}

TEST(ThermostatTestGroup, TurnOnWhenNewDesiredTempMinusHystThresholdAboveMeasuredTemp)
{
    FAIL("Test not implemented yet");
}

TEST(ThermostatTestGroup, TurnOffWhenNewDesiredTempPlusHystThresholdBelowMeasuredTemp)
{
    FAIL("Test not implemented yet");
}
