#include "gtest/gtest.h"
#include "TwoSumSorted.h"

TEST(TwoSumSorted, TwoSumSorted)
{
    TwoSumSorted sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = sol.twoSum(nums, target);
    EXPECT_FALSE(res.empty());
    EXPECT_EQ(res[0], 1);
    EXPECT_EQ(res[1], 2);
}
