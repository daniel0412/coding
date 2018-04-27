#include "gtest/gtest.h"
#include "LRU.h"

TEST(LRUCache, LRU)
{
    LRUCache sol(2);
    EXPECT_EQ(sol.get(1), -1);
    sol.put(1, 1);
    sol.put(2, 2);
    sol.get(1);
    sol.put(3, 3);
    EXPECT_EQ(sol.get(2), -1);
    sol.put(4, 4);
    EXPECT_EQ(sol.get(1), -1);
    EXPECT_EQ(sol.get(3), 3);
    EXPECT_EQ(sol.get(4), 4);
}

TEST(LRUCache, TEST_UPDATE)
{
    LRUCache sol(2);
    EXPECT_EQ(sol.get(2), -1);
    sol.put(2, 6);
    EXPECT_EQ(sol.get(1), -1);
    sol.put(1, 5);
    sol.put(1, 2);
    EXPECT_EQ(sol.get(1), 2);
    EXPECT_EQ(sol.get(2), 6);
}
