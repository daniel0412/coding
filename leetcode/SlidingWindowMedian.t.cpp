#include "gtest/gtest.h"
#include "SlidingWindowMedian.h"

TEST(SlidingWindowMedian, SlidingWindowMedian) {
    SlidingWindowMedian sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<double> res = sol.medianSlidingWindow(nums, 3);
    vector<double> target = {1, -1, -1, 3, 5, 6};

    ASSERT_EQ(res.size(), target.size());
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], target[i]);
    }
}
