
#ifdef __cplusplus
extern "C" {
#include <cstdint>
#include <cstddef>
#include <cstring>
#else
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#endif
#include "functions.h"
#include <alloca.h>

void cswap(void * a, void * b, size_t _size) {
    while (_size >= sizeof(uint64_t)) {
        uint64_t tmp = *(uint64_t *)a;
        *(uint64_t *)a = *(uint64_t *)b;
        *(uint64_t *)b = tmp;
        (int64_t *)a++;
        (int64_t *)b++;
        _size -= sizeof(uint64_t);
    }
    while (_size >= sizeof(uint32_t)) {
        uint32_t tmp = *(uint32_t *)a;
        *(uint32_t *)a = *(uint32_t *)b;
        *(uint32_t *)b = tmp;
        (int32_t *)a++;
        (int32_t *)b++;
        _size -= sizeof(uint32_t);
    }
    while (_size >= sizeof(uint16_t)) {
        uint16_t tmp = *(uint16_t *)a;
        *(uint16_t *)a = *(uint16_t *)b;
        *(uint16_t *)b = tmp;
        (int16_t*)a++;
        (int16_t*)b++;
        _size -= sizeof(uint16_t);
    }
    while (_size >= sizeof(uint8_t)) {
        uint8_t tmp = *(uint8_t *)a;
        *(uint8_t *)a = *(uint8_t *)b;
        *(uint8_t *)b = tmp;
        (int8_t *)a++;
        (int8_t *)b++;
        _size -= sizeof(uint8_t);
    }
}

void cqsort(void * const _nums, size_t _count, size_t _ele_size, int (*_fn_cmp)(const void *, const void *)) {
    if (_count < 1) { return ; }
    char * lower_bound = (char *)_nums;
    char * upper_bound = (char *)_nums + (_count - 1) * _ele_size;
    char *left=lower_bound, *right=upper_bound;
    char * base = left;
    while(left < right) {
        while (left < right && _fn_cmp(right, left) >= 0) right -= _ele_size;
        if (left < right) { cswap(left, right, _ele_size); }
        while (left < right && _fn_cmp(left, right) < 0) left += _ele_size;
        if (left < right) { cswap(right, left, _ele_size); }
    }
    cqsort(_nums, (left - lower_bound) / _ele_size, _ele_size, _fn_cmp);
    cqsort(right + _ele_size, (upper_bound - right) / _ele_size, _ele_size, _fn_cmp);
}


#ifdef __cplusplus
}
#endif
