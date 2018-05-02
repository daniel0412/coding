/* 490 The maze II
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 *through empty spaces by rolling up, down, left or right, but it won't stop
 *rolling until hitting a wall. When the ball stops, it could choose the next
 *direction.
 *
 * Given the ball's start position, the destination and the maze, determine
 * the shortest number of steps to reach the destination
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

class Maze2 {
  public:
    int hasPath(vector<vector<int> >& maze,
                vector<int>& start,
                vector<int>& destination)
    {
        if(maze.empty() || maze[0].empty())
            return true;
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // return bfs(
        // maze, start[0], start[1], destination[0], destination[1], dirs);
        vector<vector<int> > dists(
            maze.size(),
            vector<int>(maze[0].size(), numeric_limits<int>::max()));
        dists[start[0]][start[1]] = 0;
        return dfs(maze,
                   start[0],
                   start[1],
                   destination[0],
                   destination[1],
                   dists,
                   dirs);
    }

  private:
    int dfs(vector<vector<int> >& m,
            int srcx,
            int srcy,
            int dstx,
            int dsty,
            vector<vector<int> >& dists,
            const vector<pair<int, int> >& dirs)
    {
        for(const auto& d : dirs) {
            int nextx = srcx, nexty = srcy;
            int steps = dists[nextx][nexty];
            while(nextx >= 0 && nexty >= 0 && nextx < m.size() &&
                  nexty < m[0].size() && m[nextx][nexty] != 1) {
                nextx += d.first;
                nexty += d.second;
                ++steps;
            }
            nextx -= d.first;
            nexty -= d.second;
            --steps;
            if(dists[nextx][nexty] > steps) {
                dists[nextx][nexty] = steps;
                // only recursive call if not dst
                if(nextx != dstx || nexty != dsty) {
                    dfs(m, nextx, nexty, dstx, dsty, dists, dirs);
                }
            }
        }
        return dists[dstx][dsty] == numeric_limits<int>::max() ?
            -1 :
            dists[dstx][dsty];
    }

    int bfs(vector<vector<int> >& m,
            int srcx,
            int srcy,
            int dstx,
            int dsty,
            const vector<pair<int, int> >& dirs)
    {
        queue<pair<int, int> > q;
        q.emplace(srcx, srcy);
        vector<vector<int> > dists(
            m.size(), vector<int>(m[0].size(), numeric_limits<int>::max()));
        dists[srcx][srcy] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(const auto& d : dirs) {
                int steps = dists[cur.first][cur.second];
                int nextx = cur.first, nexty = cur.second;
                while(nextx >= 0 && nexty >= 0 && nextx < m.size() &&
                      nexty < m[0].size() && m[nextx][nexty] != 1) {
                    nextx += d.first;
                    nexty += d.second;
                    ++steps;
                }
                nextx -= d.first;
                nexty -= d.second;
                --steps;
                if(dists[nextx][nexty] > steps) {
                    dists[nextx][nexty] = steps;
                    // only when next ancor is not the destination, we continue
                    if(nextx != dstx || nexty != dsty) {
                        q.emplace(nextx, nexty);
                    }
                }
            }
        }
        return dists[dstx][dsty] == numeric_limits<int>::max() ?
            -1 :
            dists[dstx][dsty];
    }

  private:
};
