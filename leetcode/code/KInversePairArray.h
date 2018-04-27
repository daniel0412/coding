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

class KInversePairArray {
  public:
    int kInversePairs(int n, int k)
    {
        const int M = 1000000007;
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        for(int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                for(int m = j; m >= 0; --m) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % M;
                }
            }
        }
        return dp[n][k];
    }

  private:
};
