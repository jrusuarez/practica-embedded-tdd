#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef enum {
  ACTUATOR_ID
} gpio_id;

void GPIOSetOutput(gpio_id, bool);

#ifdef __cplusplus
}
#endif

#endif
