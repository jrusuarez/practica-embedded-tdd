#include "./ActuatorMock.h"

static bool lastValue;
static uint8_t setActuatorCalled;

void ActuatorMockInit() {
    // TODO: Implementar función de reset que se ejecuta al principio de cada test
}

uint8_t ActuatorMockSetActuatorCalledTimes() {
    // TODO: Implementar función para obtener el número de veces que se ha llamado a setActuator
}

bool ActuatorMockGetLastValue() {
    // TODO: Implementar función para obtener el último valor pasado a setActuator
}

// Override
void setActuator(bool) {
    // TODO: Implementar función de mock
}
