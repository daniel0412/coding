#include "gtest/gtest.h"
#include "SubarraySumEqualsK.h"

TEST(SubarraySumEqualsK, SubarraySumEqualsK)
{
    SubarraySumEqualsK sol;
    vector<int> nums{1,1,1};
    EXPECT_EQ(sol.subarraySum(nums, 2), 2);
}
