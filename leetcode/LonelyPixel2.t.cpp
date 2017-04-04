#include "gtest/gtest.h"
#include "LonelyPixel2.h"

TEST(LonelyPixel2, LonelyPixel2)
{
    LonelyPixel2 sol;
    vector<vector<char> > pic;
    pic.emplace_back(vector<char>{'B', 'B', 'W', 'B', 'W', 'W'});
    pic.emplace_back(vector<char>{'W', 'B', 'W', 'B', 'B', 'W'});
    pic.emplace_back(vector<char>{'W', 'B', 'W', 'B', 'B', 'W'});
    pic.emplace_back(vector<char>{'W', 'W', 'B', 'W', 'B', 'W'});

    EXPECT_EQ(0, sol.findBlackPixel(pic, 3));
}
