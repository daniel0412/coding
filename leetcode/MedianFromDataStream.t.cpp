#include "gtest/gtest.h"
#include "MedianFromDataStream.h"

TEST(MedianFromDataStream, MedianFromDataStream) {
    MedianFromDataStream sol;
    sol.addNum(1);
    sol.addNum(2);
    sol.addNum(8);
    EXPECT_EQ(2, sol.findMedian());
    sol.addNum(10);
    EXPECT_EQ(5, sol.findMedian());
}
