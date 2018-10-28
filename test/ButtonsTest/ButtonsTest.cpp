#include "CppUTest/TestHarness.h"
#include "Buttons/Buttons.h"
#include "mocks/GPIOMock.h"
#include "mocks/TimerMock.h"
#include <string.h>

TEST_GROUP(ButtonsTestGroup)
{
    void setup() {
        GPIOMockInit();
        TimerMockInit();
    }

    void teardown() {
    }
};
