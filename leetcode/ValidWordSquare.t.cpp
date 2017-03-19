#include "gtest/gtest.h"
#include "ValidWordSquare.h"

TEST(ValidWordSquare, ValidWordSquare)
{
    ValidWordSquare sol;

    vector<string> vec1 = {"abcd", "bnrt", "crmy", "dtyc"};
    EXPECT_TRUE(sol.validWordSquare(vec1));

    vector<string> vec2 = {"abcd", "bnrt", "crm", "dt"};
    EXPECT_TRUE(sol.validWordSquare(vec2));

    vector<string> vec3 = {"ball", "asee", "let", "lep"};
    EXPECT_FALSE(sol.validWordSquare(vec3));
}
