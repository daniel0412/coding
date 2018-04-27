#include "gtest/gtest.h"
#include "SortTransformedArray.h"

TEST(SortTransformedArray, tes)
{
    SortTransformedArray sol;
    int a = 1, b = 3, c = 5;
    vector<int> nums = {-4, -2, 2, 4};
    vector<int> target1 = {3, 9, 15, 33};
    vector<int> res1 = sol.sortTransformedArray(nums, a, b, c);
    for(int i = 0; i < nums.size(); ++i) {
        ASSERT_EQ(res1[i], target1[i]);
    }

    a = -1;
    vector<int> target2 = {-23, -5, 1, 7};
    vector<int> res2 = sol.sortTransformedArray(nums, a, b, c);
    for(int i = 0; i < nums.size(); ++i) {
        ASSERT_EQ(res2[i], target2[i]);
    }
}
