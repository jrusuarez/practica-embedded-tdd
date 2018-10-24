#include "./TemperatureMock.h"

static uint8_t tempInCx10;

void TemperatureMockSetTemp(uint8_t value) {
    tempInCx10 = value;
}

// Override
void TemperatureTask() {

}

// Override
uint16_t getTemperatureInCx10() {
    return tempInCx10;
}
