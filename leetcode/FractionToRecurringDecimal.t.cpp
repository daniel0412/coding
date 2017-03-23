#include "gtest/gtest.h"
#include "FractionToRecurringDecimal.h"

TEST(FractionToRecurringDecimal, FractionToRecurringDecimal)
{
    FractionToRecurringDecimal sol;
    EXPECT_EQ("0", sol.fractionToDecimal(0, 2));
    EXPECT_EQ("", sol.fractionToDecimal(2, 0));
    EXPECT_EQ("0.(3)", sol.fractionToDecimal(1, 3));
    EXPECT_EQ("-0.(3)", sol.fractionToDecimal(1, -3));
    EXPECT_EQ("-0.(012)", sol.fractionToDecimal(4, -333));
}
