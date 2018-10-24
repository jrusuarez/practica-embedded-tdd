#include "./ActuatorMock.h"

static bool lastValue;
static uint8_t setActuatorCalled;

void ActuatorMockInit() {
    setActuatorCalled = 0;
}

uint8_t ActuatorMockSetActuatorCalledTimes() {
    return setActuatorCalled;
}

bool ActuatorMockGetLastValue() {
    return lastValue;
}

// Override
void setActuator(bool value) {
    lastValue = value;
    setActuatorCalled++;
}
