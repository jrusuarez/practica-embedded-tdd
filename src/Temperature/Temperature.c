#include "./Temperature.h"
#include "HAL/ADC.h"
#include <stdbool.h>

static uint16_t lastTemperature;
bool waitingForMeasurement = false;

static void getADCValueCallback(uint16_t adcValue) {
    waitingForMeasurement = false;
    lastTemperature = ((uint32_t)adcValue * 1000 ) / ADC_MAX_VALUE;
}

void TemperatureTask() {
    if (!waitingForMeasurement) {
        waitingForMeasurement = true;
        getADCValue(getADCValueCallback);
    }
}

uint16_t getTemperatureInCx10() {
    return lastTemperature;
}
