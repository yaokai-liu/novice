#include"gtest/gtest.h"
#include "functions.h"

int64_t sum(int64_t * p, size_t c) {
    int64_t s = 0;
    for (size_t i = 0; i < c; i ++) { s += p[i]; }
    return s;
}

TEST(TestGetSum, TestGetSum){
    int64_t buffer[512];

    EXPECT_EQ(getSum(buffer, 0), sum(buffer, 0));
    EXPECT_EQ(getSum(buffer, 1), sum(buffer, 1));
    srand(time(0));
    for (int i = 0; i < 512; i++){ buffer[i] = rand(); }
    EXPECT_EQ(getSum(buffer, 512), sum(buffer, 512));

    for (int i = 0; i < 512; i ++) { buffer[i] = i + 1; }
    EXPECT_EQ(getSum(buffer, 100), sum(buffer, 100));
}

