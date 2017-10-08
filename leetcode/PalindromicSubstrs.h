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

class PalindromicSubstrs {
  public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                dp[i][j] = i == j ||
                    (s[i] == s[j] && (i + 1 = j || dp[i + 1][j - 1]));
                if(dp[i][j])
                    ++cnt;
            }
        }
        return cnt;
    }

  private:
};
