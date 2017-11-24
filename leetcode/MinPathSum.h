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

class MinPathSum {
  public:
    int minPathSum(vector<vector<int> >& grid)
    {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1, 0);
        // initialize the first row
        for(int j = 0; j < n; ++j) {
            dp[j + 1] = dp[j] + grid[0][j];
        }
        for(int i = 1; i < m; ++i) {
            // initialize the first left->right sum
            dp[0] = dp[1];
            for(int j = 0; j < n; ++j) {
                dp[j + 1] = min(dp[j] + grid[i][j], dp[j + 1] + grid[i][j]);
            }
        }
        return dp.back();
    }

  private:
};
