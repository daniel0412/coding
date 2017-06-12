#include "gtest/gtest.h"
#include "ContinuousSubarraySum.h"

TEST(ContinuousSubarraySum, ContinuousSubarraySum)
{
    ContinuousSubarraySum sol;
    vector<int> nums{23, 2, 6, 4, 7};
    int k = 6;
    EXPECT_TRUE(sol.checkSubarraySum(nums, k));
}
