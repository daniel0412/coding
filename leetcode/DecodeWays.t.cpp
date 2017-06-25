#include "gtest/gtest.h"
#include "DecodeWays.h"

TEST(DecodeWays, DecodeWays)
{
    DecodeWays sol;
    string s("10");
    EXPECT_EQ(1, sol.numDecodings(s));
    s = "160";
    EXPECT_EQ(0, sol.numDecodings(s));
    s = "110";
    EXPECT_EQ(1, sol.numDecodings(s));
}
