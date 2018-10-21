#ifndef ADC_MOCK_H
#define ADC_MOCK_H

#include "HAL/ADC.h"

void ADCMockInit(void);

void ADCMockTriggerADCValue(uint16_t value);

#endif
