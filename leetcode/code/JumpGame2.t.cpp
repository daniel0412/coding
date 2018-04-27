#include "gtest/gtest.h"
#include "JumpGame2.h"

TEST(JumpGame2, JumpGame2)
{
    JumpGame2 sol;
    vector<int> given = {2,3,1,1,4};
    EXPECT_EQ(2, sol.jump(given));
    vector<int> given2 = {3, 2, 1, 0, 4};
    EXPECT_EQ(-1, sol.jump(given2));
}
