#include "./Temperature.h"
#include "HAL/ADC.h"
#include <stdbool.h>

static uint16_t lastTemperature;

static void getADCValueCallback(uint16_t adcValue) {
    // TODO: implementar callback de valor de ADC
}

void TemperatureTask() {
    // TODO: IMplementar task de temperatura

}

uint16_t getTemperatureInCx10() {
    return lastTemperature;
}
