#include "gtest/gtest.h"
#include "AlienDict.h"

TEST(AlienDict, AlienDict)
{
    AlienDict sol;
    vector<string> dict = {"wrt", "wrf", "er", "ett", "rftt"};
    ASSERT_EQ(sol.alienOrder(dict), "wertf");
}
