#include "CppUTest/TestHarness.h"
#include "Actuator/Actuator.h"
#include "mocks/GPIOMock.h"

TEST_GROUP(ActuatorTestGroup)
{
    void setup() {
        GPIOMockInit();
    }

    void teardown() {
    }
};

TEST(ActuatorTestGroup, TurnOn)
{
    setActuator(true);
    CHECK_EQUAL(1, GPIOMockSetOutputGetCalledTimes());
    CHECK_EQUAL(ACTUATOR_ID, GPIOMockSetOutputGetLastPinId());
    CHECK_EQUAL(true, GPIOMockSetOutputGetLastValue());
}

TEST(ActuatorTestGroup, TurnOff)
{
    setActuator(false);
    CHECK_EQUAL(1, GPIOMockSetOutputGetCalledTimes());
    CHECK_EQUAL(ACTUATOR_ID, GPIOMockSetOutputGetLastPinId());
    CHECK_EQUAL(false, GPIOMockSetOutputGetLastValue());
}
