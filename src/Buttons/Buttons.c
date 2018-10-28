#include "./Buttons.h"
#include <errno.h>

#define MAX_EVENT_LISTENERS 3

void (*eventListeners[MAX_EVENT_LISTENERS])(button_event);
uint8_t eventListenersCount;

int ButtonAddEventListener(void (*callback)(button_event)) {
    return -EFAULT;
}

void ButtonTask() {

}
