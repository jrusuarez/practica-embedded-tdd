#include "./Buttons.h"
#include "HAL/GPIO.h"
#include "HAL/Timer.h"
#include <errno.h>

#define MAX_EVENT_LISTENERS 3

typedef enum {
  BUTTON_SM_IDLE = 0,
  BUTTON_SM_ANTI_REBOUND,
  BUTTON_SM_AFTER_REBOUND,
  BUTTON_SM_SHORT_DOWN,
  BUTTON_SM_LONG_DOWN
} button_state;

static button_state state;
static uint8_t buttonFlags;
static uint32_t lastStateTickMs;

void (*eventListeners[MAX_EVENT_LISTENERS])(button_event);
uint8_t eventListenersCount;

static uint8_t GetButtonFlags();
static void ThrowEvent(button_event_type, uint8_t);
static void SetNewState(button_state);
static void SMTask();
static void StateIdleHandler();
static void StateAfterReboundHandler();

void ButtonInit() {
    eventListenersCount = 0;
    buttonFlags = 0;
    state = BUTTON_SM_IDLE;
}

int ButtonAddEventListener(void (*callback)(button_event)) {
    if (eventListenersCount < MAX_EVENT_LISTENERS) {
        eventListeners[eventListenersCount] = callback;
        eventListenersCount++;
        return 0;
    }
    return -EFAULT;
}

void ButtonTask() {
    SMTask();
}

void ThrowEvent(button_event_type type, uint8_t flags) {
    button_event e = { .eventType = type,  .buttonFlags = flags };
    for (uint32_t i = 0; i < eventListenersCount; i++) {
        eventListeners[i](e);
    }
}

uint8_t GetButtonFlags() {
    uint8_t flags = 0x00;
    bool button1State = GPIOGetInput(GPIO_BUTTON_1);
    bool button2State = GPIOGetInput(GPIO_BUTTON_2);
    if (button1State) {
      flags |= BUTTON_1;
    }
    if (button2State) {
      flags |= BUTTON_2;
    }
    return flags;
}

void SMTask() {
    uint8_t flags = GetButtonFlags();

    if (flags != buttonFlags) {
        buttonFlags = flags;
        if (state != BUTTON_SM_IDLE) {
            state = BUTTON_SM_IDLE;
            return;
        }
    }

    switch (state) {
        case BUTTON_SM_IDLE:
            return StateIdleHandler();
        case BUTTON_SM_ANTI_REBOUND:
            return StateAntiReboundHandler();
        case BUTTON_SM_AFTER_REBOUND:
            return StateAfterReboundHandler();
    }
}

void UpdateLastTickMs() {
    lastStateTickMs = GetTickMs();
}

void StateIdleHandler() {
    if (buttonFlags != 0) {
        SetNewState(BUTTON_SM_ANTI_REBOUND);
    }
}

void StateAntiReboundHandler() {
    uint32_t currentTickMs = GetTickMs();
    uint32_t elapsedTime = currentTickMs - lastStateTickMs;
    if (elapsedTime > 50) {
        SetNewState(BUTTON_SM_AFTER_REBOUND);
    }
}

void StateAfterReboundHandler() {
    uint32_t currentTickMs = GetTickMs();
    uint32_t elapsedTime = currentTickMs - lastStateTickMs;
    if (elapsedTime > 50) {
        SetNewState(BUTTON_SM_SHORT_DOWN);
    }
}

void SetNewState(button_state newState) {
    state = newState;
    switch (newState) {
        case BUTTON_SM_ANTI_REBOUND:
            ThrowEvent(KEY_DOWN, buttonFlags);
            break;
        case BUTTON_SM_SHORT_DOWN:
            ThrowEvent(KEY_SHORT_DOWN, buttonFlags);
            break;
    }
    UpdateLastTickMs();
}
