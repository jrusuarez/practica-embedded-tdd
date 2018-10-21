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
    FAIL("Not implemented yet");
}

TEST(ActuatorTestGroup, TurnOff)
{
    FAIL("Not implemented yet");
}
