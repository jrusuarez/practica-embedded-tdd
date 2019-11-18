#include "./Temperature.h"
#include "HAL/ADC.h"
#include <stdbool.h>

static uint16_t lastTemperature;

static void getADCValueCallback(uint16_t adcValue) {
    // TODO: implementar callback de valor de ADC
    lastTemperature = (uint32_t)(adcValue * 1000) / ADC_MAX_VALUE;
}

void TemperatureTask() {
    // TODO: IMplementar task de temperatura
    getADCValue(getADCValueCallback);
}

uint16_t getTemperatureInCx10() {
    return lastTemperature;
}
