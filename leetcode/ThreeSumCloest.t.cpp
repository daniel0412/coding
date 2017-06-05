#include "gtest/gtest.h"
#include "ThreeSumCloest.h"

TEST(ThreeSumCloest, ThreeSumCloest)
{
    ThreeSumCloest sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int sum = sol.threeSumClosest(nums, target);
    EXPECT_EQ(sum, 2);
}
