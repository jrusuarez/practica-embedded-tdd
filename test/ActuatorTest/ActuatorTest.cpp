#include "CppUTest/TestHarness.h"
#include "Actuator/Actuator.h"
#include "HAL/GPIO.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(GPIOSetOutput, gpio_id, bool);

TEST_GROUP(ActuatorTestGroup)
{
    void setup() {
      RESET_FAKE(GPIOSetOutput);
    }

    void teardown() {
    }
};

TEST(ActuatorTestGroup, TurnOn)
{
  setActuator(true);
  CHECK_EQUAL(1, GPIOSetOutput_fake.call_count);
  CHECK_EQUAL(ACTUATOR_ID, GPIOSetOutput_fake.arg0_val);
  CHECK_EQUAL(true, GPIOSetOutput_fake.arg1_val);
}

TEST(ActuatorTestGroup, TurnOff)
{
  setActuator(false);
  CHECK_EQUAL(1, GPIOSetOutput_fake.call_count);
  CHECK_EQUAL(ACTUATOR_ID, GPIOSetOutput_fake.arg0_val);
  CHECK_EQUAL(false, GPIOSetOutput_fake.arg1_val);
}
