#include "gtest/gtest.h"
#include "MaxSquare.h"

TEST(MaxSquare, MaxSquare)
{
    MaxSquare sol;
    vector<vector<char> > matrix = {{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}};
    ASSERT_EQ(4, sol.maximalSquare(matrix));
}
