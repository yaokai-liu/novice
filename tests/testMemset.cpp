#include"gtest/gtest.h"
#include "functions.h"

TEST(TestMemset, TestMemset){
    void * ret1, * ret2;
    char buffer1[512];
    char buffer2[512];


    ret1 = _memset(buffer1, 0, 100);
    EXPECT_EQ(ret1, buffer1);
    ret2 = memset(buffer2, 0, 100);
    EXPECT_EQ(memcmp(ret1, ret2, 100), 0);

    ret1 = _memset(buffer1, 1, 512);
    EXPECT_EQ(ret1, buffer1);
    ret2 = memset(buffer2, 1, 512);
    EXPECT_EQ(memcmp(ret1, ret2, 512), 0);

    ret1 = _memset(buffer1, 255, 100);
    EXPECT_EQ(ret1, buffer1);
    ret2 = memset(buffer2, 255, 100);
    EXPECT_EQ(memcmp(ret1, ret2, 100), 0);


    ret1 = _memset(buffer1, 13487, 100);
    EXPECT_EQ(ret1, buffer1);
    ret2 = memset(buffer2, 13487, 100);
    EXPECT_EQ(memcmp(ret1, ret2, 100), 0);
}

