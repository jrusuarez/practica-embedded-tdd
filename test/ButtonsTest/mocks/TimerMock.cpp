#include "./TimerMock.h"

uint32_t tickValue;

void TimerMockInit() {
    tickValue = 0;
}

void TimerMockSetTickMsValue(uint32_t value) {
    // TODO: precargar valor de tick en ms
}

// override
uint32_t GetTickMs() {
    // TODO: devolver valor de tick en ms
}
