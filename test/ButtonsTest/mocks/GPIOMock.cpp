#include "./GPIOMock.h"

gpio_id lastPinId;
bool lastValue;
uint8_t setOutputCalled;

#define INPUT_LEN 255
// en esta tabla se puede guardar el estado de las entradas
// está sobredimensionada ya que el uso de memoria no importa demasiado aquí
bool inputValues[INPUT_LEN];

void GPIOMockInit() {
    setOutputCalled = 0;
    // TODO: Resetear valores de entrada
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
    // TODO: Precargar valor de entrada
}

// override
void GPIOSetOutput(gpio_id pinId, bool value) {
    setOutputCalled++;
    lastPinId = pinId;
    lastValue = value;
}

// override
bool GPIOGetInput(gpio_id pinId) {
    // TODO: Devolver valor de entrada
}
