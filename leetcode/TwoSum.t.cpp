#include "gtest/gtest.h"
#include "TwoSum.h"

TEST(TwoSum, TwoSum)
{
    TwoSum sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = sol.twoSum(nums, target);
    EXPECT_FALSE(res.empty());
}
