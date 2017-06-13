#include "gtest/gtest.h"
#include "ValidParentheses.h"

TEST(ValidParentheses, ValidParentheses)
{
    ValidParentheses sol;
    string s("()()([)])");
    EXPECT_FALSE(sol.isValid(s));
}
