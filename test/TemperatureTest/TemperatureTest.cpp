#include "CppUTest/TestHarness.h"
#include "Temperature/Temperature.h"
#include "HAL/ADC.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint16_t, getADCValue);

TEST_GROUP(TemperatureTestGroup)
{
  void setup() {
    RESET_FAKE(getADCValue);
  }

  void teardown() {
     // Uninit stuff
  }
};

TEST(TemperatureTestGroup, 0Degrees)
{
    getADCValue_fake.return_val = 0;
    CHECK_EQUAL(0, getTemperatureInCx10());
    CHECK_EQUAL(1, getADCValue_fake.call_count);
}

TEST(TemperatureTestGroup, 25Degrees)
{
    getADCValue_fake.return_val = ADC_MAX_VALUE / 4;
    CHECK_EQUAL(250, getTemperatureInCx10());
    CHECK_EQUAL(1, getADCValue_fake.call_count);
}

TEST(TemperatureTestGroup, 100Degrees)
{
    getADCValue_fake.return_val = ADC_MAX_VALUE;
    CHECK_EQUAL(1000, getTemperatureInCx10());
    CHECK_EQUAL(1, getADCValue_fake.call_count);
}
