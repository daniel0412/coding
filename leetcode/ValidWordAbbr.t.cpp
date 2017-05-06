#include "gtest/gtest.h"
#include "ValidWordAbbr.h"

TEST(ValidWordAbbr, ValidWordAbbr)
{
    ValidWordAbbr sol;
    string given1 = "internationalization";
    string abbr1 = "i12iz4n";
    EXPECT_TRUE(sol.validWordAbbreviation(given1, abbr1));
}

TEST(ValidWordAbbr, ValidWordAbbr1)
{
    ValidWordAbbr sol;
    string given = "word";
    vector<string> abbrs = {"word",
                            "1ord",
                            "w1rd",
                            "wo1d",
                            "wor1",
                            "2rd",
                            "w2d",
                            "wo2",
                            "1o1d",
                            "1or1",
                            "w1r1",
                            "1o2",
                            "2r1",
                            "3d",
                            "w3",
                            "4"};
    for(const auto& s : abbrs) {
        EXPECT_TRUE(sol.validWordAbbreviation(given, s));
    }

    EXPECT_FALSE(sol.validWordAbbreviation(given, "0word"));
    EXPECT_FALSE(sol.validWordAbbreviation(given, "w3d"));
}
