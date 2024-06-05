
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

void cqsort(void * const _nums, size_t _count, size_t _ele_size, int (*_fn_cmp)(const void *, const void *)) {
    if (_count < 1) { return ; }
    char * lower_bound = (char *)_nums;
    char * upper_bound = (char *)_nums + (_count - 1) * _ele_size;
    char *left=lower_bound, *right=upper_bound;
    char * base = (char *)alloca(_ele_size);
    memcpy(base, left, _ele_size);
    while(left < right) {
        while (left < right && _fn_cmp(right, base) >= 0) right -= _ele_size;
        memcpy(left, right, _ele_size);
        while (left < right && _fn_cmp(left, base) < 0) left += _ele_size;
        memcpy(right, left, _ele_size);
    }
    memcpy(right, base, _ele_size);
    cqsort(_nums, (left - lower_bound) / _ele_size, _ele_size, _fn_cmp);
    cqsort(right + _ele_size, (upper_bound - right) / _ele_size, _ele_size, _fn_cmp);
}


#ifdef __cplusplus
}
#endif
