#ifndef GPIO_MOCK_H
#define GPIO_MOCK_H

#include "HAL/GPIO.h"
#include <stdint.h>

void GPIOMockInit(void);

uint8_t GPIOMockSetOutputGetCalledTimes();
gpio_id GPIOMockSetOutputGetLastPinId();
bool GPIOMockSetOutputGetLastValue();

#endif
