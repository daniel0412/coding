#include "gtest/gtest.h"
#include "CountOfRangeSum.h"

TEST(CountOfRangeSum, CountOfRangeSum)
{
    CountOfRangeSum sol;
}

TEST(CountOfRangeSum, LowerBound)
{
    CountOfRangeSum sol;
    vector<int> given{1,2,2,2,3};
    int target = 4;
    EXPECT_EQ(5, sol.lowerBound(given, target));
}

TEST(CountOfRangeSum, UpperBound)
{
    CountOfRangeSum sol;
    vector<int> given{1,2,3};
    int target = 4;
    EXPECT_EQ(3, sol.upperBound(given, target));
}

