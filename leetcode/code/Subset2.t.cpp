#include "gtest/gtest.h"
#include "Subset2.h"

TEST(Subset2, Subset2)
{
    Subset2 sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = sol.subsets(nums);
    EXPECT_EQ(8u, res.size());
}

TEST(Subset2, Subset22)
{
    Subset2 sol;
    vector<int> nums = {1,1,1};
    vector<vector<int>> res = sol.subsets(nums);
    EXPECT_EQ(4u, res.size());
}

TEST(Subset2, Subset23)
{
    Subset2 sol;
    vector<int> nums = {1,2,2,3,3,3};
    vector<vector<int>> res = sol.subsets(nums);
    EXPECT_EQ(24u, res.size());
}
