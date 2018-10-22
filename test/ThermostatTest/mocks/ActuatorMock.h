#ifndef ACTUATOR_MOCK_H
#define ACTUATOR_MOCK_H

#include "Actuator/Actuator.h"
#include <stdint.h>

void ActuatorMockInit();

uint8_t ActuatorMockSetActuatorCalledTimes();
bool ActuatorMockGetLastValue();

#endif
