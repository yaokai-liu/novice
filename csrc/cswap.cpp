
#include "functions.h"

void cswap(void * a, void * b, size_t _size) {
    uint8_t *a8, *b8;
    a8 = static_cast<uint8_t *>(a);
    b8 = static_cast<uint8_t *>(b);
    for (size_t i = 0; i < _size; i++) {
        uint8_t tmp = a8[i];
        a8[i] = b8[i];
        b8[i] = tmp;
    }
}