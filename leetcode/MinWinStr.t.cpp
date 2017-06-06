#include "gtest/gtest.h"
#include "MinWinStr.h"

TEST(MinWinStr, MinWinStr)
{
    MinWinStr sol;
    string s("ADOBECODEBANC");
    string t("ABC");
    string res = sol.minWindow(s, t);
    EXPECT_EQ(res, "BANC");
}
