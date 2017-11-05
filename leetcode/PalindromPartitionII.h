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

class PalindromPartitionII {
  public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= i; --j) {
                if(i == j ||
                   (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))) {
                    dp[i][j] = true;
                }
            }
        }
        vector<int> cnt(n, numeric_limits<int>::max());
        cnt[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(dp[0][i])
                cnt[i] = 0;
            else {
                for(int j = 0; j <= i; ++j) {
                    if(dp[0][j] && dp[j + 1][i]) {
                        cnt[i] = min(cnt[i], cnt[j] + 1);
                    }
                }
            }
        }
        return cnt.back();
    }

  private:
};
