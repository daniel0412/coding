#include "gtest/gtest.h"
#include "SlidingWindowMedian.h"

// Failed this test, due to multiset.erase() operation
TEST(SlidingWindowMedian, DuplicateTest) {
    SlidingWindowMedian sol;
    vector<int> nums = {7,0,3,9,9,9,1,7,2,3};
    vector<double> res = sol.medianSlidingWindow(nums, 6);
    vector<double> target = {8.00000,6.00000,8.00000,8.00000,5.00000};

    ASSERT_EQ(res.size(), target.size());
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], target[i]);
    }
}

// Failed this test, due to multiset.erase() operation
TEST(SlidingWindowMedian, RuntimeErrorTest) {
    SlidingWindowMedian sol;
    vector<int> nums = {5,5,8,1,4,7,1,3,8,4};
    vector<double> res = sol.medianSlidingWindow(nums, 8);
    vector<double> target = {4.5,4.5,4.0};

    ASSERT_EQ(res.size(), target.size());
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], target[i]);
    }
}

// Failed this test, due to (a+b)*0.5 overflow, should be a*0.5+b*0.5
TEST(SlidingWindowMedian, OverflowTest) {
    SlidingWindowMedian sol;
    vector<int> nums1 = {2147483647, 2147483647};
    vector<double> res1 = sol.medianSlidingWindow(nums1, 2);

    EXPECT_EQ(res1[0], 2147483647.00000);
}
