#include "gtest/gtest.h"
#include "MoveZero.h"

TEST(MoveZero, MoveZero)
{
    MoveZero sol;
    vector<int> nums = {1, 0, 3, 0, 12};
    vector<int> targets = {1, 3, 12, 0, 0};
    sol.moveZeroes(nums);
    for(int i = 0; i < nums.size(); ++i) {
        EXPECT_EQ(nums[i], targets[i]);
    }
}
