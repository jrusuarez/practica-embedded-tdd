#include "./TimerMock.h"

uint32_t tickValue;

void TimerMockInit() {
    tickValue = 0;
}

void TimerMockSetTickMsValue(uint32_t value) {
    tickValue = value;
}

// override
uint32_t GetTickMs() {
    return tickValue;
}
