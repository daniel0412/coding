#include "gtest/gtest.h"
#include "Integer2English.h"

TEST(Integer2English, Integer2English)
{
    Integer2English sol;
    cout << sol.numberToWords(10100012) << endl;
}
