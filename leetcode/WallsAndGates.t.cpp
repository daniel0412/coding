#include "gtest/gtest.h"
#include "WallsAndGates.h"

TEST(WallsAndGates, WallsAndGates)
{
    WallsAndGates sol;
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>{INF, -1, 0, INF});
    matrix.push_back(vector<int>{INF, INF, INF, -1});
    matrix.push_back(vector<int>{INF, -1, INF, -1});
    matrix.push_back(vector<int>{0, -1, INF, INF});
    sol.wallsAndGates(matrix);

    vector<vector<int> > target;
    target.push_back(vector<int>{3, -1, 0, 1});
    target.push_back(vector<int>{2, 2, 1, -1});
    target.push_back(vector<int>{1, -1, 2, -1});
    target.push_back(vector<int>{0, -1, 3, 4});

    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[0].size(); ++j) {
            EXPECT_EQ(matrix[i][j], target[i][j]);
        }
    }
}
