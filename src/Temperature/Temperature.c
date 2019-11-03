#include "./Temperature.h"
#include "HAL/ADC.h"

uint16_t getTemperatureInCx10() {
    // TODO: Implementar función de temperatura
    uint16_t adcValue = getADCValue();
    return (uint32_t)(adcValue * (uint32_t)1000) / ADC_MAX_VALUE;
}
