/*
 *
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

// needs to encapsulate it better, will do it after interview
// KEY TAKEAWAYS
// 1. directions are captured by left/down/right/up, and treat it as a cycular array
// 2. robot itself needs to always maintains its own orientation, and current location
// 3. after each move, robot backtraced to its original location
//
class Robot {
  public:
    Robot(vector<string>& grid, int i, int j)
        : grid(grid),
          i(i),
          j(j),
          d(3),  // assume robot facing up when starts
          dirs({{0, -1}, {-1, 0}, {0, 1}, {1, 0}})  // left, down, right, up
    {
    }

    bool move()
    {
        int di = dirs[d].first, dj = dirs[d].second;
        if(i + di < 0 || i + di >= grid.size() || j + dj < 0 ||
           j + dj >= grid[i].size() || grid[i + di][j + dj] == '+')
            return false;
        i += di;
        j += dj;
        return true;
    }

    // Robot will stay on the same cell after calling Turn*. k indicates how
    void turnRight(int k) { d = (d + k) % 4; }

    void turnLeft(int k) { d = (d + 4 - k) % 4; }

    void setd(int di) {d = di;}

    void clean() { grid[i][j] = ' '; }
    void printLoc() { cout << "pos: (" << i << ", " << j << ")" << endl; }
    void printGrid()
    {
        for(auto s : grid)
            cout << s << endl;
    }

  private:
    vector<string>& grid;
    int i;
    int j;
    int d;
    vector<pair<int, int> > dirs;
};

// after each move, recover the direction of robots
bool moveLeft(Robot& r)
{
    //r.turnRight(1);
    r.setd(0);
    bool possible = r.move();
    //r.turnLeft(1);
    return possible;
}

bool moveRight(Robot& r)
{
    //r.turnLeft(1);
    r.setd(2);
    bool possible = r.move();
    //r.turnRight(1);
    return possible;
}

bool moveUp(Robot& r)
{
    r.setd(3);
    bool possible = r.move();
    return possible;
}

bool moveDown(Robot& r)
{
    r.set(1);
    //r.turnRight(2);
    bool possible = r.move();
    //r.turnRight(2);
    return possible;
}
void dfs(Robot& r,
         unordered_map<int, unordered_set<int> >& visited,
         int i,
         int j,
         int level) // for debugging purposes
{
    // left, up, down
    if(visited.count(i) && visited[i].count(j))
        return;
    r.clean();
    // r.print();
    visited[i].insert(j);
    if(level == 0) r.printLoc();
    if(moveLeft(r)) {
        dfs(r, visited, i, j - 1, level + 1);
        moveRight(r);
    }
    if(level == 0) r.printLoc();
    if(moveUp(r)) {
        dfs(r, visited, i + 1, j, level+1);
        moveDown(r);
    }
    if(level == 0) r.printLoc();
    if(moveDown(r)) {
        dfs(r, visited, i - 1, j, level+1);
        moveUp(r);
    }
    if(level == 0) r.printLoc();
    if(moveRight(r)) {
        dfs(r, visited, i, j + 1, level+1);
        moveLeft(r);
    }
    return;
}

void cleanAll(Robot& r)
{
    unordered_map<int, unordered_set<int> > visited;
    dfs(r, visited, 0, 0, 0);
}

int main()
{
    vector<string> layout({"++++++++++",
                           "+........+",
                           "+........+",
                           "+.+......+",
                           "++++.+++++",
                           "+.....+",
                           "+++++++"});
    Robot r(layout, 2, 4);
    cout << "before cleaning" << endl;
    r.printLoc();
    r.printGrid();

    cleanAll(r);
    cout << "after cleaning" << endl;
    r.printLoc();
    r.printGrid();

    return 0;
}
