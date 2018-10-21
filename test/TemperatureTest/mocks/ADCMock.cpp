#include "./ADCMock.h"
#include <stdlib.h>
void (*adcValueCallback)(uint16_t) = NULL;

void ADCMockInit() {

}

void ADCMockTriggerADCValue(uint16_t value) {
    if (adcValueCallback != NULL) {
      (*adcValueCallback)(value);
    }
}

// override
int getADCValue(void (*callback)(uint16_t)) {
    adcValueCallback = callback;
}
