#include "gtest/gtest.h"
#include "utils.h"

TEST(Utils, LowerBound)
{
    vector<int> given{1,2,2,2,3};
    int target = 4;
    EXPECT_EQ(5, lowerBound(given, target));
}

TEST(Utils, UpperBound)
{
    vector<int> given{1,2,3};
    int target = 4;
    EXPECT_EQ(3, upperBound(given, target));
}
