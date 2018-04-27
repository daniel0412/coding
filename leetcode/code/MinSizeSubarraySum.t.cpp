#include "gtest/gtest.h"
#include "MinSizeSubarraySum.h"

TEST(MinSizeSubarraySum, MinSizeSubarraySum)
{
    MinSizeSubarraySum sol;
    vector<int> nums{2,3,1,2,4,3};
    int s = 7;
    EXPECT_EQ(2, sol.minSubArrayLen(s, nums));
}
