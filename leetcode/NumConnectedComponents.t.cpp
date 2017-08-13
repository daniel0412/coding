#include "gtest/gtest.h"
#include "NumConnectedComponents.h"

TEST(NumConnectedComponents, NumConnectedComponents)
{
    NumConnectedComponents sol;
    int n = 5;
    vector<pair<int,int>> edges;
    EXPECT_EQ(n, sol.countComponents(n, edges));
}

TEST(NumConnectedComponents, NumConnectedComponents2)
{
    NumConnectedComponents sol;
    int n = 6;
    vector<pair<int,int>> edges= {{2,3}, {4,5}, {2,5}};
    EXPECT_EQ(3, sol.countComponents(n, edges));
}
