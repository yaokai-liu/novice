#include "functions.h"

void cswap(void * a, void * b, size_t _size) {
    uint64_t *a64, *b64;
    a64 = reinterpret_cast<uint64_t *>(a);
    b64 = reinterpret_cast<uint64_t *>(b);
    while (_size >= sizeof(uint64_t)) {
        uint64_t tmp = *a64;
        *a64 = *b64;
        *b64 = tmp;
        a64 ++; b64 ++;
        _size -= sizeof(uint64_t);
    }
    uint32_t *a32 = reinterpret_cast<uint32_t *>(a64);
    uint32_t *b32 = reinterpret_cast<uint32_t *>(a64);
    while (_size >= sizeof(uint32_t)) {
        uint32_t tmp = *a32;
        *a32 = *b32;
        *b32 = tmp;
        a32 ++; b32 ++;
        _size -= sizeof(uint32_t);
    }
    uint16_t *a16 = reinterpret_cast<uint16_t *>(a32);
    uint16_t *b16 = reinterpret_cast<uint16_t *>(b32);
    while (_size >= sizeof(uint16_t)) {
        uint16_t tmp = *a16;
        *a16 = *b16;
        *b16 = tmp;
        a16 ++; b16 ++;
        _size -= sizeof(uint16_t);
    }
    uint8_t *a8 = reinterpret_cast<uint8_t *>(a16);
    uint8_t *b8 = reinterpret_cast<uint8_t *>(b16);
    while (_size >= sizeof(uint8_t)) {
        uint8_t tmp = *a8;
        *a8 = *b8;
        *b8 = tmp;
        a8 ++; b8 ++;
        _size -= sizeof(uint8_t);
    }
}

void cqsort(void * const _nums, size_t _count, size_t _ele_size, int (*_fn_cmp)(const void *, const void *)) {
    if (_count < 1) { return ; }
    char * lower_bound = (char *)_nums;
    char * upper_bound = (char *)_nums + (_count - 1) * _ele_size;
    char *left=lower_bound, *right=upper_bound;
    while(left < right) {
        while (left < right && _fn_cmp(right, left) >= 0) right -= _ele_size;
        if (left < right) { cswap(left, right, _ele_size); }
        while (left < right && _fn_cmp(left, right) < 0) left += _ele_size;
        if (left < right) { cswap(right, left, _ele_size); }
    }
    cqsort(_nums, (left - lower_bound) / _ele_size, _ele_size, _fn_cmp);
    cqsort(right + _ele_size, (upper_bound - right) / _ele_size, _ele_size, _fn_cmp);
}

