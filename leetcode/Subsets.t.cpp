#include "gtest/gtest.h"
#include "Subsets.h"

TEST(Subsets, Subsets)
{
    Subsets sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = sol.subsets(nums);
    EXPECT_EQ(8u, res.size());
}
