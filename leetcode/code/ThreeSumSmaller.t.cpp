#include "gtest/gtest.h"
#include "ThreeSumSmaller.h"

TEST(ThreeSumSmaller, ThreeSumSmaller)
{
    ThreeSumSmaller sol;
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;
    int count = sol.threeSumSmaller(nums, target);
    EXPECT_EQ(count, 2);
}
