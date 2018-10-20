#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void TemperatureTask();
uint16_t getTemperatureInCx10();

#ifdef __cplusplus
}
#endif

#endif
