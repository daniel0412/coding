#include "gtest/gtest.h"
#include "GraphValidTree.h"

TEST(GraphValidTree, GraphValidTree)
{
    GraphValidTree sol;
    vector<pair<int,int>> edges0 = {{0, 1}, {0, 2}};
    ASSERT_TRUE(sol.validTree(3, edges0));
    vector<pair<int,int>> edges1 = {{0, 1}, {0, 2}, {1,2}};
    ASSERT_FALSE(sol.validTree(3, edges1));
}
