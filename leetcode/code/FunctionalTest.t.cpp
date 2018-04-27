#include "gtest/gtest.h"
#include "FunctionalTest.h"

TEST(FunctionalTest, FunctionalTest) 
{
    FunctionalTest sol;
    auto f = [](int x){ return x+3; };
    EXPECT_EQ(5, sol.testFunctional(f, 2));
    auto fa = [](int x){ return x*2; };
    EXPECT_EQ(4, sol.testFunctional(fa, 2));
}
