#include "gtest/gtest.h"
#include "NumOfIslandII.h"

TEST(NumOfIslandII, NumOfIslandII)
{
    NumOfIslandII sol;
    int m = 3, n = 3;
    vector<pair<int, int> > p = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
    vector<int> res = sol.numIslands2(m, n, p);
    vector<int> target = {1, 1, 2, 3};
    for(size_t i = 0; i < target.size(); ++i) {
        ASSERT_EQ(res[i], target[i]);
    }
}
