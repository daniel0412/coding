#include "gtest/gtest.h"
#include "LonelyPixel.h"

TEST(LonelyPixel, LonelyPixel)
{
    LonelyPixel sol;
    vector<vector<char> > pic;
    pic.emplace_back(vector<char>{'B', 'W', 'W'});
    pic.emplace_back(vector<char>{'W', 'B', 'W'});
    pic.emplace_back(vector<char>{'W', 'W', 'B'});
    EXPECT_EQ(3, sol.findLonelyPixle(pic));
}
