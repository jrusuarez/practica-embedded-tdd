#ifndef BUTTONS_H
#define BUTTONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define BUTTON_1 0x01
#define BUTTON_2 0x02

typedef enum {
    KEY_DOWN,
    KEY_SHORT_DOWN,
    KEY_SHORT_UP,
    KEY_LONG_DOWN
} button_event_type;

typedef struct {
    uint8_t buttonFlags;
    button_event_type eventType;
} button_event;

void ButtonInit();
int ButtonAddEventListener(void (*callback)(button_event));
void ButtonTask();

#ifdef __cplusplus
}
#endif

#endif
