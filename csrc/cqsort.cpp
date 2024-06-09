#include "functions.h"

void cqsort(void * const _nums, size_t _count, size_t _ele_size, int (*_fn_cmp)(const void *, const void *)) {
    if (!_nums || _count < 1 || !_ele_size || !_fn_cmp ) { return ; }
    char * lower_bound = (char *)_nums;
    char * upper_bound = (char *)_nums + (_count - 1) * _ele_size;
    char *left=lower_bound, *right=upper_bound;
    while(left < right) {
        while (left < right && _fn_cmp(right, left) >= 0) right -= _ele_size;
        if (left < right) { cswap(left, right, _ele_size); left += _ele_size; }
        while (left < right && _fn_cmp(right, left) >= 0) left += _ele_size;
        if (left < right) { cswap(right, left, _ele_size); right -= _ele_size; }
    }
    cqsort(_nums, (left - lower_bound) / _ele_size, _ele_size, _fn_cmp);
    cqsort(right + _ele_size, (upper_bound - right) / _ele_size, _ele_size, _fn_cmp);
}
