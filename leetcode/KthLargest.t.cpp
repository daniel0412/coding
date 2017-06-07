#include "gtest/gtest.h"
#include "KthLargest.h"

TEST(KthLargest, KthLargest)
{
    KthLargest sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    EXPECT_EQ(5, sol.findKthLargest(nums, k));
}

TEST(KthLargest, KthLargest1)
{
    KthLargest sol;
    vector<int> nums = {99, 99};
    int k = 1;
    EXPECT_EQ(99, sol.findKthLargest(nums, k));
}

TEST(KthLargest, KthLargest2)
{
    KthLargest sol;
    vector<int> nums = {2, 2};
    int k = 1;
    EXPECT_EQ(2, sol.findKthLargest(nums, k));
}
