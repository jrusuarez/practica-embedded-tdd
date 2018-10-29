#include "./GPIOMock.h"

gpio_id lastPinId;
bool lastValue;
uint8_t setOutputCalled;

#define INPUT_LEN 255
// en esta tabla se puede guardar el estado de las entradas
// está sobredimensionada ya que el uso de memoria no importa demasiado aquí
bool inputValues[INPUT_LEN];

void ResetInputs() {
    for (uint32_t i = 0; i < INPUT_LEN; i++) {
        inputValues[i] = false;
    }
}

void GPIOMockInit() {
    setOutputCalled = 0;
    ResetInputs();
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

void GPIOMockSetInputState(gpio_id pinId, bool value) {
    inputValues[pinId] = value;
}

// override
void GPIOSetOutput(gpio_id pinId, bool value) {
    setOutputCalled++;
    lastPinId = pinId;
    lastValue = value;
}

// override
bool GPIOGetInput(gpio_id pinId) {
    return inputValues[pinId];
}
