#include "gtest/gtest.h"
#include "JumpGame.h"

TEST(JumpGame, JumpGame)
{
    JumpGame sol;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    EXPECT_TRUE(sol.canJump(nums1));
    vector<int> nums2 = {3, 2, 1, 0, 4};
    EXPECT_FALSE(sol.canJump(nums2));
}
