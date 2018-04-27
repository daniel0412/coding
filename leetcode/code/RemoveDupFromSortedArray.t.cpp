#include "gtest/gtest.h"
#include "RemoveDupFromSortedArray.h"

TEST(RemoveDupFromSortedArray, RemoveDupFromSortedArray)
{
    RemoveDupFromSortedArray sol;
    vector<int> nums({1,1,2});
    EXPECT_EQ(2, sol.removeDuplicates(nums));
}
