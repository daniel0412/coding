#include "gtest/gtest.h"
#include "PeekingIterator.h"

TEST(PeekingIterator, PeekingIterator)
{
    PeekingIterator sol(vector<int>{1, 2, 3});
    EXPECT_EQ(1, sol.next());
    EXPECT_EQ(2, sol.peek());
    EXPECT_EQ(2, sol.next());
    EXPECT_TRUE(sol.hasNext());
    EXPECT_EQ(3, sol.peek());
    EXPECT_TRUE(sol.hasNext());
    EXPECT_EQ(3, sol.next());
    EXPECT_FALSE(sol.hasNext());
}
