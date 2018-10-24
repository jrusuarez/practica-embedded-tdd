#include "CppUTest/TestHarness.h"
#include "Thermostat/Thermostat.h"
#include "mocks/ActuatorMock.h"
#include "mocks/TemperatureMock.h"

static void initTestConditions(uint8_t hystInCx10, uint8_t desiredTempInCx10, uint8_t measuredTempInCx10);
static void step1Test();
static void step2Test();
static void step3Test();

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
    step1Test();
}

TEST(ThermostatTestGroup, StayOnIfMeasuredTempBelowDesiredTempPlusHystThreshold)
{
    step2Test();
}

TEST(ThermostatTestGroup, TurnOffWhenAlreadyOnAndMeasuredTempAboveDesiredTempPlusHystThreshold)
{
    step3Test();
}

TEST(ThermostatTestGroup, StayOffWhenMeasuredTempAboveDesiredTempMinusHystThreshold)
{
    step3Test();
    ActuatorMockInit();

    TemperatureMockSetTemp(211);
    ThermostatTask();
    CHECK_EQUAL(0, ActuatorMockSetActuatorCalledTimes());
}

TEST(ThermostatTestGroup, TurnOnWhenNewDesiredTempMinusHystThresholdAboveMeasuredTemp)
{
    initTestConditions(10, 200, 210);
    ThermostatTask();

    ThermostatSetTemp(230);
    CHECK_EQUAL(1, ActuatorMockSetActuatorCalledTimes());
    CHECK_TRUE(ActuatorMockGetLastValue());
}

TEST(ThermostatTestGroup, TurnOffWhenNewDesiredTempPlusHystThresholdBelowMeasuredTemp)
{
    initTestConditions(10, 200, 180);
    ThermostatTask();
    CHECK_EQUAL(1, ActuatorMockSetActuatorCalledTimes());
    CHECK_TRUE(ActuatorMockGetLastValue());

    ThermostatSetTemp(160);
    CHECK_EQUAL(2, ActuatorMockSetActuatorCalledTimes());
    CHECK_FALSE(ActuatorMockGetLastValue());
}

void initTestConditions(uint8_t hystInCx10, uint8_t desiredTempInCx10, uint8_t measuredTempInCx10) {
    ThermostatOptions opts = {hystInCx10: 10, desiredTempInCx10: 200};
    TemperatureMockSetTemp(measuredTempInCx10);
    ThermostatInit(&opts);
    ThermostatTask();
}

void step1Test() {
    initTestConditions(10, 200, 210);
    TemperatureMockSetTemp(180);
    ThermostatTask();

    CHECK_EQUAL(1, ActuatorMockSetActuatorCalledTimes());
    CHECK_TRUE(ActuatorMockGetLastValue());
}

void step2Test() {
    step1Test();
    ActuatorMockInit();

    TemperatureMockSetTemp(209);
    ThermostatTask();
    CHECK_EQUAL(0, ActuatorMockSetActuatorCalledTimes());
}

void step3Test() {
    step2Test();
    ActuatorMockInit();

    TemperatureMockSetTemp(220);
    ThermostatTask();
    CHECK_EQUAL(1, ActuatorMockSetActuatorCalledTimes());
    CHECK_FALSE(ActuatorMockGetLastValue());
}
