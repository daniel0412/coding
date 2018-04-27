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

class NumOfIsland {
  public:
    int numIslands(vector<vector<char> >& grid)
    {
        if(grid.empty())
            return 0;
        int nums = 0;
        for(size_t i = 0; i < grid.size(); ++i) {
            for(size_t j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++nums;
                }
            }
        }
        return nums;
    }

  private:
    void dfs(vector<vector<char> >& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        if(grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
