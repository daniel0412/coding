#include "gtest/gtest.h"
#include "RegularExpressionMatch.h"

TEST(RegularExpressionMatch, RegularExpressionMatch)
{
    RegularExpressionMatch sol;
    string s, p;
    s = "aab";
    p = "c*a*b";
    EXPECT_TRUE(sol.isMatch(s, p));
    s = "aa";
    p = ".*";
    EXPECT_TRUE(sol.isMatch(s, p));
    s = "ab";
    p = ".*";
    EXPECT_TRUE(sol.isMatch(s, p));
    s = "aaa";
    p = "aaa";
    EXPECT_TRUE(sol.isMatch(s, p));
    s = "aaa";
    p = "aa";
    EXPECT_FALSE(sol.isMatch(s, p));
}
