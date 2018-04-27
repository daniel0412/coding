#include "gtest/gtest.h"
#include "Maze2.h"

TEST(Maze2, MazeTest)
{  
    Maze2 sol;
    vector<vector<int> > maze;
    maze.emplace_back(vector<int>{0, 0, 1, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 1, 0});
    maze.emplace_back(vector<int>{1, 1, 0, 1, 1});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    vector<int> start{0, 4};
    vector<int> dest{4, 4};
    EXPECT_EQ(12, sol.hasPath(maze, start, dest));
}

TEST(Maze2, MazeTest2)
{
    Maze2 sol;
    vector<vector<int> > maze;
    maze.emplace_back(vector<int>{0, 0, 1, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 1, 0});
    maze.emplace_back(vector<int>{1, 1, 0, 1, 1});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    vector<int> start{0, 4};
    vector<int> dest{3, 2};
    EXPECT_EQ(-1, sol.hasPath(maze, start, dest));
}
