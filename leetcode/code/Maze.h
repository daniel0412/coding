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
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        return dfs(
            maze, start[0], start[1], destination[0], destination[1], dirs);
    }

  private:
    bool dfs(vector<vector<int> >& m,
             int srcx,
             int srcy,
             int dstx,
             int dsty,
             const vector<pair<int, int> >& dirs)
    {
        if(srcx == dstx && srcy == dsty)
            return true;
        m[srcx][srcy] = -1;
        for(const auto& d : dirs) {
            int nextx = srcx, nexty = srcy;
            while(nextx >= 0 && nexty >= 0 && nextx < m.size() &&
                  nexty < m[0].size() && m[nextx][nexty] != 1) {
                nextx += d.first;
                nexty += d.second;
            }
            nextx -= d.first;
            nexty -= d.second;
            if(m[nextx][nexty] != -1) {
                if(dfs(m, nextx, nexty, dstx, dsty, dirs))
                    return true;
            }
        }
        return false;
    }

    bool bfs(vector<vector<int> >& m,
             int srcx,
             int srcy,
             int dstx,
             int dsty,
             const vector<pair<int, int> >& dirs)
    {
        queue<pair<int, int> > q;
        q.emplace(srcx, srcy);
        m[srcx][srcy] = -1;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(const auto& d : dirs) {
                int nextx = cur.first, nexty = cur.second;
                while(nextx >= 0 && nexty >= 0 && nextx < m.size() &&
                      nexty < m[0].size() && m[nextx][nexty] != 1) {
                    nextx += d.first;
                    nexty += d.second;
                }

                nextx -= d.first;
                nexty -= d.second;
                if(nextx == dstx && nexty == dsty)
                    return true;
                if(m[nextx][nexty] != -1) {
                    q.emplace(nextx, nexty);
                    m[nextx][nexty] = -1;
                }
            }
        }
        return false;
    }
};
