#include"gtest/gtest.h"
#include "functions.h"

TEST(testAbs32, TestAbs){
    EXPECT_EQ(abs32(0), 0);
    EXPECT_EQ(abs32(1), 1);
    EXPECT_EQ(abs32(-1), 1);

    EXPECT_EQ(abs32(-183746387), 183746387);
    EXPECT_EQ(abs32(1938746), 1938746);
}

TEST(testAbs32Bound, TestAbs) {

    EXPECT_EQ(abs32(INT32_MAX), INT32_MAX);

    // specially case: abs((int32_t)-2147483648) is itself.
    EXPECT_EQ(abs32(INT32_MIN), INT32_MIN);
}


TEST(testAbs64, TestAbs){
    EXPECT_EQ(abs64(0), 0);
    EXPECT_EQ(abs64(1), 1);
    EXPECT_EQ(abs64(-1), 1);

    EXPECT_EQ(abs64(-183746387), 183746387);
    EXPECT_EQ(abs64(1938746), 1938746);

    EXPECT_EQ(abs64(INT32_MAX), INT32_MAX);
    EXPECT_EQ(abs64(INT32_MIN), 2147483648L);
}

TEST(testAbs64Bound, TestAbs) {

    EXPECT_EQ(abs64(INT64_MAX), INT64_MAX);

    // specially case: abs((int64_t)-9223372036854775808) is itself.
    EXPECT_EQ(abs64(INT64_MIN), INT64_MIN);
}

