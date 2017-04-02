#include "gtest/gtest.h"
#include "Logger.h"

TEST(Logger, Logger)
{
    Logger sol;
    EXPECT_TRUE(sol.shouldPrintMessage(1, "foo"));
    EXPECT_TRUE(sol.shouldPrintMessage(3, "foo1"));
    EXPECT_FALSE(sol.shouldPrintMessage(5, "foo"));
    EXPECT_FALSE(sol.shouldPrintMessage(8, "foo1"));
    EXPECT_FALSE(sol.shouldPrintMessage(10, "foo"));
    EXPECT_TRUE(sol.shouldPrintMessage(11, "foo"));
}
