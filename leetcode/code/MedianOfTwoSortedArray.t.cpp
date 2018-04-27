#include "gtest/gtest.h"
#include "MedianOfTwoSortedArray.h"

TEST(MedianOfTwoSortedArray, ) {
    MedianOfTwoSortedArray sol;

    vector<int> nums11 = {1, 3};
    vector<int> nums21 = {2};
    double median1 = sol.findMedianSortedArrays(nums11, nums21);
    EXPECT_EQ(median1, 2);

    vector<int> nums12 = {1, 2};
    vector<int> nums22 = {3, 4};
    double median2 = sol.findMedianSortedArrays(nums12, nums22);
    EXPECT_EQ(2.5, median2);
}
