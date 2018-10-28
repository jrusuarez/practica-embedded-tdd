#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef enum {
  ACTUATOR_ID,
  GPIO_BUTTON_1,
  GPIO_BUTTON_2
} gpio_id;

void GPIOSetOutput(gpio_id, bool);
bool GPIOGetInput(gpio_id);

#ifdef __cplusplus
}
#endif

#endif
