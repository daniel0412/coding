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

class PaintHouseII {
  public:
    // original dp without space optimization
    int minCostII(vector<vector<int> >& costs)
    {
        int n = cost.size(), k = cost[0].size();
        vector<vector<int> > dp(n, vector<int>(k, 0));
        // follow-up: return the cost-minimal solution
        vector<int> path(n, 0);
        int prevMinc1 = 0, prevMinc2 = 0, prevColor = -1;
        for(int i = 0; i < n; ++i) {
            int curMinc1 = numeric_limits<int>::min();
            int curMinc2 = numeric_limits<int>::min();
            int curColor = -1;
            for(int j = 0; j < k; ++j) {
                dp[i][k] =
                    cost[i][k] + (prevColor == j ? prevMinc2 : prevMinc1);
                if(dp[i][j] < curMinc1) {
                    curMinc2 = curMinc1;
                    curMinc1 = dp[i][j];
                    curColor = j;
                }
                else if(dp[i][j] < curMin2) {
                    curMin2 = dp[i][j];
                }
            }
            prevMinc1 = curMinc1;
            prevMinc2 = curMinc2;
            prevColor = curColor;
            // update current color choise
            path[i] = curColor;
        }
        return prevMinc1;
    }


    // dp with space optimization
    int minCostII(vector<vector<int> >& costs)
    {
        if(costs.empty() || costs[0].empty())
            return 0;
        // previous top 2 minium cost and the color used for top 1st minium
        // cost
        int minc1 = 0, minc2 = 0, mini1 = -1;
        for(size_t i = 0; i < costs.size(); ++i) {
            int tmp_minc1 = INT_MAX, tmp_minc2 = INT_MAX, tmp_mini1 = -1;
            for(size_t j = 0; j < costs[i].size(); ++j) {
                int tmpcost = costs[i][j] + (j == mini1 ? minc2 : minc1);
                if(tmpcost < tmp_minc1) {
                    tmp_minc2 = tmp_minc1;
                    tmp_minc1 = tmpcost;
                    tmp_mini1 = j;
                }
                else if(tmpcost < tmp_minc2) {
                    tmp_minc2 = tmpcost;
                }
            }
            minc1 = tmp_minc1;
            mini1 = tmp_mini1;
            minc2 = tmp_minc2;
        }
        return minc1;
    }

  private:
};
