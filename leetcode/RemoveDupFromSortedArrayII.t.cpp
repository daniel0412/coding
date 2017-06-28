#include "gtest/gtest.h"
#include "RemoveDupFromSortedArrayII.h"

TEST(RemoveDupFromSortedArrayII, RemoveDupFromSortedArrayII)
{
    RemoveDupFromSortedArrayII sol;
    vector<int> nums({1,1,1,2,2,3});
    EXPECT_EQ(5, sol.removeDuplicates(nums));
}
