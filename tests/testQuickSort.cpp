#include "gtest/gtest.h"
#include<cstdint>
#include <cstdlib>
#include <cstring>
#include <random>
#include "functions.h"


#define sqsort  qsort
#define BUFFER_LEN  0x8000
#define ELE_TYPE    int64_t

int cmp64(const void *a, const void *b) {
    return *(int64_t *)a > *(int64_t *)b ? 1 : -1;
}

TEST(TestQuickSortOrderedInt64Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = i ; }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);
    for (int i = 0; i < BUFFER_LEN; i++) {
        printf("%ld\t%ld\n", buffer1[i], buffer3[i]);
    }

    free(buffer1);
    free(buffer2);
    free(buffer3);
}

TEST(TestQuickSortRandomInt64Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = random(); }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);


    free(buffer1);
    free(buffer2);
    free(buffer3);
}

TEST(TestQuickSortConstInt64Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    int64_t value = random();
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = value; }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);

    free(buffer1);
    free(buffer2);
    free(buffer3);
}

TEST(TestQuickSortReverseInt64Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    int8_t shift = (int8_t) random() % 64;
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = BUFFER_LEN - i; buffer1[i] <<= shift; }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp64);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);

    free(buffer1);
    free(buffer2);
    free(buffer3);
}
#undef ELE_TYPE

#define ELE_TYPE    int32_t

int cmp32(const void *a, const void *b) {
    return *(int32_t *)a > *(int32_t *)b ? 1 : -1;
}

TEST(TestQuickSortOrderedInt32Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = i << (random() % 32); }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);


    free(buffer1);
    free(buffer2);
    free(buffer3);
}

TEST(TestQuickSortRandomInt32Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = (int32_t) random(); }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);


    free(buffer1);
    free(buffer2);
    free(buffer3);
}

TEST(TestQuickSortConstInt32Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    auto value = (int32_t) random();
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = value; }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);

    free(buffer1);
    free(buffer2);
    free(buffer3);
}

TEST(TestQuickSortReverseInt32Array, TestQuickSort) {
    auto * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    auto * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srandom(time(nullptr));
    int8_t shift = (int8_t) random() % 32;
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = BUFFER_LEN - i; buffer1[i] <<= shift; }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp32);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);

    free(buffer1);
    free(buffer2);
    free(buffer3);
}
