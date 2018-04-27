#include "gtest/gtest.h"
#include "CountOfRangeSum.h"

TEST(CountOfRangeSum, CountOfRangeSum)
{
    CountOfRangeSum sol;
    vector<int> given{-2, 5, -1};
    int target = 3;
    EXPECT_EQ(target, sol.countRangeSum(given, -2, 2));
}
