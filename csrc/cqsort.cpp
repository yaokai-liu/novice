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
    return ;
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

