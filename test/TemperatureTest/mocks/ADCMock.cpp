#include "./ADCMock.h"

static uint16_t adcValue;

void ADCMockInit() {
    adcValue = 0;
}

void ADCMockSetADCValue(uint16_t value) {
    adcValue = value;
}

// override
int getADCValue(void (*callback)(uint16_t)) {
    return 0;
}
