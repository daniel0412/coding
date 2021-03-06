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

class FlipGameII {
  public:
      // recursive solution with full string
    bool canWin(string s)
    {
        for(int i = 1; i < s.size(); ++i) {
            // player 1 flip and palyer 2 fails after player 1's flip
            if(s[i - 1] == '+' && s[i] == '+' &&
               !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
                return true;
            }
        }
        return false;
    }

    // recursive solution with partial string
    bool canWin(const string& s, int l, int r)
    {
        if(r - l < 1)
            return false;
        for(int i = l + 1; i <= r; ++i) {
            if(s[i - 1] == '+' && s[i] == '+') {
                if(!canWin(s, l, i - 2) && !canWin(s, i = 1, r)) {
                    return true;
                }
            }
        }
        return false;
    }

    // dp solution, similar to predict winner
    bool canWinDP(const string& s)
    {
        if(s.size() < 2)
            return false;
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));

        for(int l = n - 2; l >= 0; --l) {
            for(int r = l + 1; r < n; ++r) {
                if(l + 1 == r && s[l] == '+' && s[r] == '+') {
                    dp[l][r] = true;
                }
                else {
                    for(int k = l + 1; k <= r; ++k) {
                        if(s[k - 1] == '+' && s[k] == '+') {
                            if((k < 2 || !dp[l][k - 2]) &&
                               (k >= n - 1 || !dp[k + 1][r])) {
                                dp[l][r] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

  private:
};
