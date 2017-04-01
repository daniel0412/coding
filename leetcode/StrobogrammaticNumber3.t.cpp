#include "gtest/gtest.h"
#include "StrobogrammaticNumber3.h"

TEST(StrobogrammaticNumber3, Count)
{
    StrobogrammaticNumber3 sol;
    long long totalCount = 0;
    EXPECT_EQ(3, sol.count(1));

    totalCount = 0;
    EXPECT_EQ(4, sol.count(2));

    totalCount = 0;
    EXPECT_EQ(20, sol.count(4));
}

TEST(StrobogrammaticNumber3, CountGreaterThan)
{
    StrobogrammaticNumber3 sol;
    long long totalCount = 0;
    sol.countGreaterThan("0", 0, totalCount);
    EXPECT_EQ(2, totalCount);

    totalCount = 0;
    sol.countGreaterThan("11", 0, totalCount);
    EXPECT_EQ(3, totalCount);

    totalCount = 0;
    sol.countGreaterThan("101", 0, totalCount);
    EXPECT_EQ(11, totalCount);
}

TEST(StrobogrammaticNumber3, CountLessThan)
{
    StrobogrammaticNumber3 sol;
    long long totalCount = 0;
    sol.countLessThan("8", 0, totalCount);
    EXPECT_EQ(2, totalCount);

    totalCount = 0;
    sol.countLessThan("96", 0, totalCount);
    EXPECT_EQ(3, totalCount);

    totalCount = 0;
    sol.countLessThan("986", 0, totalCount);
    EXPECT_EQ(11, totalCount);
}


TEST(StrobogrammaticNumber3, StrobogrammaticInRange)
{
    StrobogrammaticNumber3 sol;
    EXPECT_EQ(3, sol.strobogrammaticInRange("50", "100"));

    EXPECT_EQ(5, sol.strobogrammaticInRange("5", "100"));
}
