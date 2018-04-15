/* 286 Walls and Gates
 *
 * You are given a m x n 2D grid initialized with these three possible values.
 *   -1: A wall or an obstacle.
 *    0: A gate.
 *  INF: Infinity means an empty room.
 *
 *  We use the value 2^31 - 1 = 2147483647 to represent INF
 *  as you may assume that the distance to a gate is less than 2147483647.
 *
 *  Fill each empty room with the distance to its nearest gate.
 *  If it is impossible to reach a gate, it should be filled with INF.
 *
 *  For example, given the 2D grid:
 *  INF  -1  0  INF
 *  INF INF INF  -1
 *  INF  -1 INF  -1
 *    0  -1 INF INF
 *
 *  After running your function, the 2D grid should be:
 *  3  -1   0   1
 *  2   2   1  -1
 *  1  -1   2  -1
 *  0  -1   3   4
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
const int INF = 2147483647;

class WallsAndGates {
  public:
    void wallsAndGates(vector<vector<int> >& rooms)
    {
        // startFromGates(rooms);
        // bfs solution
        bfsFromGates(rooms);
    }

    void startFromGates(vector<vector<int> >& rooms)
    {
        for(int i = 0; i < rooms.size(); ++i) {
            for(int j = 0; j < rooms[0].size(); ++j) {
                if(rooms[i][j] == 0) {
                    dfsFromGates(rooms, i, j, 0);
                }
            }
        }
    }

  private:
    void dfsFromGates(vector<vector<int> >& rooms, int row, int col, int steps)
    {
        if(row < 0 || row >= rooms.size() || col < 0 ||
           col >= rooms[0].size() || rooms[row][col] <= steps)
            return;
        rooms[row][col] = steps;
        dfsFromGates(rooms, row - 1, col, steps + 1);
        dfsFromGates(rooms, row + 1, col, steps + 1);
        dfsFromGates(rooms, row, col - 1, steps + 1);
        dfsFromGates(rooms, row, col + 1, steps + 1);
    }

    void bfsFromGates(vector<vector<int> >& rooms)
    {
        queue<pair<int, int> > myque;
        for(int i = 0; i < rooms.size(); ++i) {
            for(int j = 0; j < rooms[0].size(); ++j) {
                if(rooms[i][j] == 0) {
                    myque.push(make_pair(i, j));
                }
            }
        }

        vector<pair<int, int> > loc{make_pair(1, 0),
                                    make_pair(0, 1),
                                    make_pair(-1, 0),
                                    make_pair(0, -1)};
        while(!myque.empty()) {
            int i = myque.front().first, j = myque.front().second;
            myque.pop();
            for(auto& p : loc) {
                int iLoc = i + p.first, jLoc = j + p.second;
                if(iLoc < 0 || iLoc >= rooms.size() || jLoc < 0 ||
                   jLoc >= rooms[0].size() ||
                   rooms[iLoc][jLoc] <= rooms[i][j] + 1)
                    continue;
                rooms[iLoc][jLoc] = rooms[i][j] + 1;
                myque.push(make_pair(iLoc, jLoc));
            }
        }
    }

};
