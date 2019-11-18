#include "./Actuator.h"
#include "HAL/GPIO.h"

void setActuator(bool value) {
    GPIOSetOutput(ACTUATOR_ID, value);
}
