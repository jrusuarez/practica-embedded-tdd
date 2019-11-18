#include "CppUTest/TestHarness.h"
#include "Temperature/Temperature.h"
#include "fff.h"
#include <stdio.h>
#include "HAL/ADC.h"

DEFINE_FFF_GLOBALS;

typedef void (*getADCValueCb)(uint16_t);
FAKE_VALUE_FUNC(int, getADCValue, getADCValueCb);

static uint16_t mockAdcValue;

int getADCValueMock(void (*callback)(uint16_t)) {
  (*callback)(mockAdcValue);
  // Llamar al callback con un valor prefijado de ADC
  return 0;
}

TEST_GROUP(TemperatureTestGroup)
{
    void setup() {
    }

    void teardown() {
    }
};

TEST(TemperatureTestGroup, 0Degrees)
{
    getADCValue_fake.custom_fake = getADCValueMock;
    mockAdcValue = 0;
    TemperatureTask();
    uint16_t currentTemp = getTemperatureInCx10();
    CHECK_EQUAL(0, currentTemp);
}

TEST(TemperatureTestGroup, 25Degrees)
{
    getADCValue_fake.custom_fake = getADCValueMock;
    mockAdcValue = ADC_MAX_VALUE / 4;
    TemperatureTask();
    uint16_t currentTemp = getTemperatureInCx10();
    CHECK_EQUAL(250, currentTemp);
}

TEST(TemperatureTestGroup, 100Degrees)
{
  getADCValue_fake.custom_fake = getADCValueMock;
  mockAdcValue = ADC_MAX_VALUE;
  TemperatureTask();
  uint16_t currentTemp = getTemperatureInCx10();
  CHECK_EQUAL(1000, currentTemp);
}
