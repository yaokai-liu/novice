#include"gtest/gtest.h"
#include "functions.h"

TEST(TestAbs32, TestAbs){
    EXPECT_EQ(abs32(0), abs(0));
    EXPECT_EQ(abs32(1), abs(1));
    EXPECT_EQ(abs32(-1), abs(-1));
    EXPECT_EQ(abs32(INT32_MAX), abs(INT32_MAX));
    EXPECT_EQ(abs32(INT32_MIN), abs(INT32_MIN));
}


TEST(TestAbs64, TestAbs){
    EXPECT_EQ(abs64(1), labs(1));
    EXPECT_EQ(abs64(0), labs(0));
    EXPECT_EQ(abs64(-1), labs(-1));
    EXPECT_EQ(abs64(INT32_MAX), labs(INT32_MAX));
    EXPECT_EQ(abs64(INT32_MIN), labs(INT32_MIN));
    EXPECT_EQ(abs64(INT64_MAX), labs(INT64_MAX));
    EXPECT_EQ(abs64(INT64_MIN), labs(INT64_MIN));
}
