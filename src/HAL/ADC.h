#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

// 3V equivalen al máximo valor de ADC y a 100ºC
// 0V equivalen a 0ºC y, como es lógico, equivaldrían al valor 0 del ADC
#define ADC_MAX_VALUE 4096

void ADCInit();
uint16_t getADCValue();


#ifdef __cplusplus
}
#endif

#endif
