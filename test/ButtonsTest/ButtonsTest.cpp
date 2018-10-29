#include "CppUTest/TestHarness.h"
#include "Buttons/Buttons.h"
#include "mocks/GPIOMock.h"
#include "mocks/TimerMock.h"
#include <string.h>
#include <errno.h>

static button_event lastEvent;
static uint32_t eventCallbackCount;

static void ResetData();
static void ButtonEventCallback(button_event);

TEST_GROUP(ButtonsTestGroup)
{
    void setup() {
        GPIOMockInit();
        TimerMockInit();
        ResetData();
    }

    void teardown() {
    }
};

TEST(ButtonsTestGroup, AddEventListenerSuccess) {
    ButtonInit();
    int result = ButtonAddEventListener(ButtonEventCallback);
    CHECK_EQUAL(0, result);
}

TEST(ButtonsTestGroup, AddEventListenerOverflowError) {
    ButtonInit();
    for (uint32_t i = 0; i < 3; i++) {
        ButtonAddEventListener(ButtonEventCallback);
    }
    int result = ButtonAddEventListener(ButtonEventCallback);
    CHECK_EQUAL(-EFAULT, result);
}

TEST(ButtonsTestGroup, KeyDownEvent) {
    ButtonInit();
    ButtonAddEventListener(ButtonEventCallback);
    GPIOMockSetInputState(GPIO_BUTTON_1, true);
    ButtonTask();
    CHECK_EQUAL(1, eventCallbackCount);
    CHECK_EQUAL(KEY_DOWN, lastEvent.eventType);
    CHECK_EQUAL(BUTTON_1, lastEvent.buttonFlags);
}

TEST(ButtonsTestGroup, KeyShortDownEvent) {
    ButtonInit();
    ButtonAddEventListener(ButtonEventCallback);
    GPIOMockSetInputState(GPIO_BUTTON_1, true);
    TimerMockSetTickMsValue(0);
    ButtonTask();
    TimerMockSetTickMsValue(51);
    ButtonTask();
    ResetData();
    TimerMockSetTickMsValue(102);
    ButtonTask();
    CHECK_EQUAL(1, eventCallbackCount);
    CHECK_EQUAL(KEY_SHORT_DOWN, lastEvent.eventType);
    CHECK_EQUAL(BUTTON_1, lastEvent.buttonFlags);
}

void ResetData() {
    memset(&lastEvent, 0, sizeof(button_event));
    eventCallbackCount = 0;
}

void ButtonEventCallback(button_event e) {
    memcpy(&lastEvent, &e, sizeof(button_event));
    eventCallbackCount++;
}
