/* 490 The maze
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 *through empty spaces by rolling up, down, left or right, but it won't stop
 *rolling until hitting a wall. When the ball stops, it could choose the next
 *direction.
 *
 * Given the ball's start position, the destination and the maze, determine
 *whether the ball could stop at the destination.
 *
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means
 *the empty space. You may assume that the borders of the maze are all walls.
 *The start and destination coordinates are represented by row and column
 *indexes.
 *
 * Example 1
 *
 * Input 1: a maze represented by a 2D array
 *
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 *
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (4, 4)
 *
 * Output: true
 * Explanation: One possible way is : left -> down -> left -> down -> right ->
 *down -> right.
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

class Maze {
  public:
    bool hasPath(vector<vector<int> >& maze,
                 vector<int>& start,
                 vector<int>& destination)
    {
        if(maze.empty() || maze[0].empty())
            return true;
        resetStates(maze.size(), maze[0].size());
        dfs(maze, start[0], start[1], destination[0], destination[1]);
        return d_pathFound;
    }

  private:
    vector<pair<int, int> > d_directions;
    bool d_pathFound;

    void resetStates(int numRows, int numCols)
    {
        d_pathFound = false;
        d_directions.clear();
        d_directions.emplace_back(make_pair(1, 0));
        d_directions.emplace_back(make_pair(-1, 0));
        d_directions.emplace_back(make_pair(0, 1));
        d_directions.emplace_back(make_pair(0, -1));
    }

    void dfs(vector<vector<int> >& maze,
             int startRow,
             int startCol,
             int destRow,
             int destCol)
    {
        if(d_pathFound)
            return;
        if(startRow == destRow && startCol == destCol) {
            d_pathFound = true;
            return;
        }

        if(maze[startRow][startCol] == -1)
            return;

        for(auto p : d_directions) {
            int curRow = startRow;
            int curCol = startCol;
            while(curRow >= 0 && curRow < maze.size() && curCol >= 0 &&
                  curCol < maze[0].size() && maze[curRow][curCol] != 1) {
                curRow += p.first;
                curCol += p.second;
            }
            int stopRow = curRow - p.first;
            int stopCol = curCol - p.second;
            if(stopRow == startRow && stopCol == startCol) {
                maze[startRow][startCol] = -1;
                continue;
            }
            dfs(maze, stopRow, stopCol, destRow, destCol);
            maze[startRow][startCol] = -1;
        }
    }
};
