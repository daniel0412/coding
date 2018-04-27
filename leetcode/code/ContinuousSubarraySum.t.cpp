#include "gtest/gtest.h"
#include "ContinuousSubarraySum.h"

TEST(ContinuousSubarraySum, ContinuousSubarraySum)
{
    ContinuousSubarraySum sol;
    vector<int> nums{3,0};
    int k = 5;
    EXPECT_TRUE(sol.checkSubarraySum(nums, k));
}
