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
        // dp[i][j] to record if the substring of s starting from index i to
        // index j is a palindrom
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        // substring starting index i from last to the first char
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                // decide if substring from i to j is also a palindrom
                if(s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }

  private:
};
