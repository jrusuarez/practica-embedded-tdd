#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
  uint8_t hystInCx10;
  uint8_t desiredTempInCx10;
} ThermostatOptions;

void ThermostatInit(ThermostatOptions*);
void ThermostatSetTemp(uint8_t tempInCx10);
void ThermostatTask();


#ifdef __cplusplus
}
#endif

#endif
