#include "gtest/gtest.h"
#include "WildcardMatching.h"

TEST(WildcardMatching, isMatch) {
    WildcardMatching sol;

    EXPECT_FALSE( sol.isMatch("aa", "a") );
    EXPECT_FALSE( sol.isMatch("aaa", "as") );
    EXPECT_FALSE( sol.isMatch("aab", "c*b*a") );

    EXPECT_TRUE( sol.isMatch("aa", "aa") );
    EXPECT_TRUE( sol.isMatch("aa", "*") );
    EXPECT_TRUE( sol.isMatch("aa", "a*") );
    EXPECT_TRUE( sol.isMatch("ab", "?*") );
    EXPECT_TRUE( sol.isMatch("aaaa", "***a") );
}
