#include "gtest/gtest.h"
#include "StrobogrammaticNumber.h"

TEST(StrobogrammaticNumber, StrobogrammaticNumber)
{
    StrobogrammaticNumber sol;
    EXPECT_TRUE(sol.isStrobogrammatic("11"));
    EXPECT_TRUE(sol.isStrobogrammatic("69"));
    EXPECT_TRUE(sol.isStrobogrammatic("689"));
    EXPECT_FALSE(sol.isStrobogrammatic("699"));
    EXPECT_FALSE(sol.isStrobogrammatic("2"));

}
