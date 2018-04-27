#include "gtest/gtest.h"
#include "MedianFromDataStream.h"

TEST(MedianFromDataStream, MedianFromDataStream) {
    MedianFromDataStream sol;
    sol.addNum(-1);
    EXPECT_EQ(-1, sol.findMedian());
    sol.addNum(-2);
    EXPECT_EQ(-1.5, sol.findMedian());
    sol.addNum(-3);
    EXPECT_EQ(-2, sol.findMedian());
    sol.addNum(-4);
    EXPECT_EQ(-2.5, sol.findMedian());
    sol.addNum(-5);
    EXPECT_EQ(-3, sol.findMedian());
}
