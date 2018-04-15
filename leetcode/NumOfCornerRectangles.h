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

class NumOfCornerRectangles {
  public:
    // brute force
    int countCornerRectangles(vector<vector<int> >& grid)
    {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                // find up/left corner
                if(grid[r][c]) {
                    for(int c1 = c + 1; c1 < n; ++c1) {
                        // find up/right corner
                        if(grid[r][c1]) {
                            // find donw/left/right corner
                            for(r1 = r + 1; r1 < m; ++r1) {
                                if(grid[r1][c] && grid[r1][c1])
                                    ++cnt;
                            }
                        }
                    }
                }
            }
        }
    }

    // loop all up/down rows, and find in these two rows, how many cols have 1s
    // then use choose 2 out of these n cols
    int countCornerRectangles(vector<vector<int> >& grid)
    {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for(int r1 = 0; r1 < m - 1; ++r1) {
            for(int r2 = r1 + 1; r2 < m; ++r2) {
                if(grid[r1][0] && grid[r2][0]) {
                    int cnt = 0;
                    for(c = 0; c < n; ++c) {
                        if(grid[r1][c] && grid[r2][c])
                            ++cnt;
                    }
                    res += (cnt - 1) * cnt / 2;
                }
            }
        }
        return res;
    }

    // third optimization can be make is
    // when loop over 1st row, record col locations where 1 exists,
    // for all next row, only  check these col locations

  private:
};
