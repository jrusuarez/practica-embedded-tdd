#include "./ADCMock.h"

static uint16_t adcValue;

void ADCMockInit() {
    adcValue = 0;
}

void ADCMockSetADCValue(uint16_t value) {
    adcValue = value;
}

// override
uint16_t getADCValue() {
    return adcValue;
}
