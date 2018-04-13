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

class IslandPerimeter {
  public:
    int islandPerimeter(vector<vector<int> >& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // all 1 cell, count all four edges
                if(grid[i][j] == 1) {
                    cnt += 4;
                    // remove edges between connected 1 cells
                    // only consider up/left for each 1 cell
                    // this way, no excessive count
                    if(i > 0 && grid[i - 1][j])
                        cnt -= 2;
                    if(j > 0 && grid[i][j - 1])
                        cnt -= 2;
                }
            }
        }
        return cnt;
    }

  private:
};
