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
    EXPECT_EQ("0.5", sol.fractionToDecimal(1, 2));
}


TEST(FractionToRecurringDecimal, OverflowTest)
{
    FractionToRecurringDecimal sol;
    EXPECT_EQ("0.0000000004656612873077392578125", sol.fractionToDecimal(-1, -2147483648));
    EXPECT_EQ("-2147483648", sol.fractionToDecimal(-2147483648, 1));
}
