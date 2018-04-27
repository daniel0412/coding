#include "gtest/gtest.h"
#include "MovingAvgFromDS.h"

TEST(MovingAvgFromDS, MovingAvgFromDS)
{
    MovingAvgFromDS sol(3);
    EXPECT_EQ(sol.next(1), 1);
    EXPECT_EQ(sol.next(10), (1 + 10 * 1.0) / 2);
    EXPECT_EQ(sol.next(3), (1 + 10 + 3) * 1.0 / 3);
    EXPECT_EQ(sol.next(5), (10 + 3 + 5) * 1.0 / 3);
}
