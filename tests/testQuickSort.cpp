#include "gtest/gtest.h"
#include<cstdint>
#include <cstdlib>
#include <cstring>
#include "functions.h"


#define sqsort  qsort
#define ELE_TYPE    int64_t
#define BUFFER_LEN  0x800

int cmp(const void *a, const void *b) {
    return *(ELE_TYPE *)a > *(ELE_TYPE *)b ? 1 : -1;
}

TEST(TestQuickSort1, TestQuickSort) {
    ELE_TYPE * buffer1 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    ELE_TYPE * buffer2 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));
    ELE_TYPE * buffer3 = (ELE_TYPE *) malloc(BUFFER_LEN * sizeof(ELE_TYPE));

    srand(time(0));
    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = rand(); }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);


    for (int i = 0; i < BUFFER_LEN; i++){ buffer1[i] = BUFFER_LEN - i; }
    memcpy(buffer2, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));
    memcpy(buffer3, buffer1, BUFFER_LEN * sizeof(ELE_TYPE));

    sqsort(buffer1, BUFFER_LEN, sizeof(ELE_TYPE), cmp);
    cqsort(buffer2, BUFFER_LEN, sizeof(ELE_TYPE), cmp);
    _qsort(buffer3, BUFFER_LEN, sizeof(ELE_TYPE), cmp);
    EXPECT_EQ(memcmp(buffer2, buffer1, BUFFER_LEN), 0);
    EXPECT_EQ(memcmp(buffer3, buffer1, BUFFER_LEN), 0);

    free(buffer1);
    free(buffer2);
    free(buffer3);
}
