#ifndef EXAMPLE_H
#define EXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stdbool.h>

uint8_t sum(uint8_t, uint8_t);

char* concat(char*, char*);

bool notOp(bool);
bool xorOp(bool, bool);

#ifdef __cplusplus
}
#endif

#endif
