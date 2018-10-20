#include "./Example.h"
#include <string.h>

uint8_t sum(uint8_t a, uint8_t b) {
  return a + b;
}

char* concat(char *s1, char *s2) {
  return strcat(s1, s2);
}

bool notOp(bool a) {
  return !a;
}

bool xorOp(bool a, bool b) {
  return (a || b) && !(a && b);
}
