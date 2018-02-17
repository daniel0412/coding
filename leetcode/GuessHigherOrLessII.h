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

class GuessHigherOrLessII {
  public:
    int getMoneyAmount(int n) { return minmax(n); }

    // minimax:
    // consider all the cases, find the worst case, then minimize it
    int minmax(int n)
    {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        for(int end = 2; end <= n; ++end) {
            for(int start = end - 1; start > 0; --start) {
                if(start + 1 = end) {
                    dp[start][end] = start;
                    continue;
                }
                dp[start][end] = numeric_limits<int>::max();
                for(int mid = start + 1; mid < end; ++mid) {
                    dp[start][end] =
                        min(dp[start][end],
                            mid + max(dp[start][mid - 1], dp[mid + 1][end]));
                }
            }
        }
        return dp[1][n];
    }

  private:
};
