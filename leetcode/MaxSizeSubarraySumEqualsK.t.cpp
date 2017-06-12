#include "gtest/gtest.h"
#include "MaxSizeSubarraySumEqualsK.h"

TEST(MaxSizeSubarraySumEqualsK, MaxSizeSubarraySumEqualsK)
{
 
    MaxSizeSubarraySumEqualsK sol;
    vector<int> nums = {-2, -1, 2, 1};
    int k = 1;
    EXPECT_EQ(sol.maxSubArrayLen(nums, k), 2);
}
