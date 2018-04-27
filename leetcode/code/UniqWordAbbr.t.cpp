#include "gtest/gtest.h"
#include "UniqWordAbbr.h"

TEST(UniqWordAbbr, UniqWordAbbr)
{
    UniqWordAbbr sol(vector<string>{"deer", "door", "cake", "card"});
    EXPECT_FALSE(sol.isUniqe("dear"));
    EXPECT_FALSE(sol.isUniqe("cane"));
    EXPECT_TRUE(sol.isUniqe("cart"));
    EXPECT_TRUE(sol.isUniqe("make"));
}
