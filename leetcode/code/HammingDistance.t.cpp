#include "gtest/gtest.h"
#include "HammingDistance.h"

TEST(HammingDistance, HammingDistance)
{
    HammingDistance sol;
    int c = sol.hammingDistance(93,73);
    EXPECT_EQ(2, c);
}
