#include "gtest/gtest.h"
#include "TotalHammingDistance.h"

TEST(TotalHammingDistance, TotalHammingDistance)
{
    TotalHammingDistance sol;
    vector<int> nums({2, 14, 4});
    EXPECT_EQ(6, sol.totalHammingDistance(nums));
}
