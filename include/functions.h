
#ifndef NOVICE_FUNCTIONS_H
#define NOVICE_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include<stddef.h>
#include<stdint.h>

int32_t abs32(int32_t _num);
int64_t abs64(int64_t _num);
void * _memset(void * _dest, int _ch, size_t _count);
int64_t getSum(int64_t * _nums, size_t _count);
void cswap(void * a, void * b, size_t _size);
void cqsort(void * const _nums, size_t _count, size_t _ele_size,
            int (*_fn_cmp)(const void *, const void *));
void _qsort(void * const _nums, size_t _count, size_t _ele_size,
            int (*_fn_cmp)(const void *, const void *));

#ifdef __cplusplus
}
#endif

#endif // NOVICE_FUNCTIONS_H