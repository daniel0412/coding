#include "gtest/gtest.h"
#include "Maze.h"

TEST(Maze, Maze)
{
    Maze sol;
    vector<vector<int> > maze;
    maze.emplace_back(vector<int>{0, 0, 1, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 1, 0});
    maze.emplace_back(vector<int>{1, 1, 0, 1, 1});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    vector<int> start{0, 4};
    vector<int> dest{4, 4};
    EXPECT_TRUE(sol.hasPath(maze, start, dest));
}

TEST(Maze, Maze1)
{
    Maze sol;
    vector<vector<int> > maze;
    maze.emplace_back(vector<int>{0, 0, 1, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    maze.emplace_back(vector<int>{0, 0, 0, 1, 0});
    maze.emplace_back(vector<int>{1, 1, 0, 1, 1});
    maze.emplace_back(vector<int>{0, 0, 0, 0, 0});
    vector<int> start{0, 4};
    vector<int> dest{3, 2};
    EXPECT_FALSE(sol.hasPath(maze, start, dest));
}
