#include "gtest/gtest.h"
#include "ThreeSum.h"

TEST(ThreeSum, ThreeSum)
{
    ThreeSum sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sol.threeSum(nums);
    EXPECT_EQ(res.size(), 2);
}
