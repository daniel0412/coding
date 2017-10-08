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

class LongestPalindromicSubseq {
  public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; ++i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = s[i] == s[j] ? 2 + dp[i + 1][j - 1] :
                                          max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }

  private:
};
