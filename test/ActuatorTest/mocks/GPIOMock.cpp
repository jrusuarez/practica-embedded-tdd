#include "./GPIOMock.h"

gpio_id lastPinId;
bool lastValue;

uint8_t setOutputCalled;

void GPIOMockInit() {
    setOutputCalled = 0;
}

uint8_t GPIOMockSetOutputGetCalledTimes() {
    return setOutputCalled;
}

gpio_id GPIOMockSetOutputGetLastPinId() {
    return lastPinId;
}

bool GPIOMockSetOutputGetLastValue() {
    return lastValue;
}

// override
void GPIOSetOutput(gpio_id pinId, bool value) {
    setOutputCalled++;
    lastPinId = pinId;
    lastValue = value;
}
