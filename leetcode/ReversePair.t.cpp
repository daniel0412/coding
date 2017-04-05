#include "gtest/gtest.h"
#include "ReversePair.h"

TEST(ReversePair, ReversePair)
{
    ReversePair sol;
    vector<int> nums{3};
    EXPECT_EQ(0, sol.reversePairs(nums));
    nums.push_back(1);
    EXPECT_EQ(1, sol.reversePairs(nums));
    nums.clear();

    vector<int> nums1{2, 4, 3, 5, 1};
    EXPECT_EQ(3, sol.reversePairs(nums1));
}

TEST(ReversePair, Overflow)
{
    ReversePair sol;
    vector<int> nums{2147483647,
                     2147483647,
                     2147483647,
                     2147483647,
                     2147483647,
                     2147483647};
    EXPECT_EQ(0, sol.reversePairs(nums));
}
