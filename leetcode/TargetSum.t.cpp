#include "gtest/gtest.h"
#include "TargetSum.h"

TEST(TargetSum, TargetSum)
{
    TargetSum sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    ASSERT_EQ(5, sol.findTargetSumWays(nums, target));
}
