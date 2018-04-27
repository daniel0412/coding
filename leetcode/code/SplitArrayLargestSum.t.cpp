#include "gtest/gtest.h"
#include "SplitArrayLargestSum.h"

TEST(SplitArrayLargestSum, SplitArrayLargestSum)
{
    SplitArrayLargestSum sol;
    vector<int> nums({1,2,3,4,5});
    int m = 2;
    EXPECT_EQ(9, sol.splitArray(nums, m));
}
