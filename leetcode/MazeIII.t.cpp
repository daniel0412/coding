#include "gtest/gtest.h"
#include "MazeIII.h"

TEST(MazeIII, MazeTest)
{  
    MazeIII sol;
    vector<vector<int> > maze;
    maze.emplace_back(vector<int>{0, 0, 1, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 1, 0});
    maze.emplace_back(vector<int>{1, 1, 0, 1, 1});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    vector<int> start{0, 4};
    vector<int> dest{3, 2};
    EXPECT_EQ("ldldrd", sol.hasPath(maze, start, dest));
}

TEST(Maze2, MazeTest2)
{
    MazeIII sol;
    vector<vector<int> > maze;
    maze.emplace_back(vector<int>{0, 0, 1, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 1, 0});
    maze.emplace_back(vector<int>{1, 1, 0, 1, 1});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    vector<int> start{0, 4};
    vector<int> dest{0, 1};
    EXPECT_EQ("ldlur", sol.hasPath(maze, start, dest));
}
