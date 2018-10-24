#include "./Thermostat.h"
#include "Temperature/Temperature.h"
#include "Actuator/Actuator.h"
#include <stdio.h>

static uint8_t hystInCx10;
static uint8_t desiredTempInCx10;
static bool active;

void ThermostatInit(ThermostatOptions *opts) {
    hystInCx10 = opts->hystInCx10;
    desiredTempInCx10 = opts->desiredTempInCx10;
    active = false;
}

void ThermostatSetTemp(uint8_t tempInCx10) {
    desiredTempInCx10 = tempInCx10;
    ThermostatTask();
}

void ThermostatTask() {
    uint16_t mTempInCx10 = getTemperatureInCx10();
    if (!active) {
        if ((mTempInCx10 + hystInCx10) < desiredTempInCx10) {
            setActuator(true);
            active = true;
        }
    } else {
        if ((desiredTempInCx10 + hystInCx10) < mTempInCx10) {
            setActuator(false);
            active = false;
        }
    }
}
