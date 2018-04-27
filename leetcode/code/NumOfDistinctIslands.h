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

class NumOfDistinctIslands {
  public:
    using vv = vector<vector<int> >;
    int numDistinctIslands(vector<vector<int> >& grid)
    {
        // use set
        set<vector<pair<int, int> > > s;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    vector<pair<int, int> > island;
                    dfs(grid, i, j, i, j, island);
                    s.insert(island);
                }
            }
        }
        return s.size();
    }

    // (x0, y0): most top/left point of the island, used to normalize the island
    void dfs(vv& grid,
             const int x0,
             const int y0,
             int x,
             int y,
             vector<pair<int, int> >& island)
    {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
           grid[x][y] != 1)
            return;
        grid[x][y] = -1;
        island.emplace_back(x - x0, y - y0);
        dfs(grid, x0, y0, x - 1, y, island);
        dfs(grid, x0, y0, x + 1, y, island);
        dfs(grid, x0, y0, x, y - 1, island);
        dfs(grid, x0, y0, x, y + 1, island);
    }

  private:
};
