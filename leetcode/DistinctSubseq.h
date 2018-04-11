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

class DistinctSubseq {
  public:
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        // empty t to any length of s
        for(int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        // empty s to any length of t is ignored, since dp is all 0
        //
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                dp[i][j] += (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[m][n];
    }


  private:
};
