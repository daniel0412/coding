#include "gtest/gtest.h"
#include "SearchInRotatedSortedArray.h"

TEST(SearchInRotatedSortedArray, SearchInRotatedSortedArray)
{
    SearchInRotatedSortedArray sol;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2, 3};
    EXPECT_EQ(2, sol.search(nums, 6));
}

TEST(SearchInRotatedSortedArray, SearchInRotatedSortedArray2)
{
    SearchInRotatedSortedArray sol;
    vector<int> nums{5, 1, 3};
    EXPECT_EQ(0, sol.search(nums, 5));
}
