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
        // create 2D dp to records if s[i...j] is palindrom
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= i; --j) {
                if(i == j ||
                   (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))) {
                    dp[i][j] = true;
                }
            }
        }

        // another 1D dp to deduce min cuts
        vector<int> cnt(n, numeric_limits<int>::max());
        cnt[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(dp[0][i])
                cnt[i] = 0;
            else {
                for(int j = i - 1; j >= 0; --j) {
                    if(dp[j + 1][i]) {
                        cnt[i] = min(cnt[i], cnt[j] + 1);
                    }
                }
            }
        }
        return cnt.back();
    }

    int conciseVersion(string s)
    {
        int n = s.size();
        vector<vector<bool> > p(n, vector<bool>(n, false));
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; ++i)
            cnt[i] = i;

        cnt[0] = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = i; j >= 0; --j) {
                if(s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
                    p[j][i] = true;
                    if(j == 0)
                        cnt[j] = 0;
                    else
                        cnt[i] = min(cnt[j - 1] + 1, cnt[i]);
                }
            }
        }
        return cnt.back();
    }

    int twoSidedExtending(string s)
    {
        int n = s.size();
        vector<int> cnt(n, numeric_limits<int>::max());
        for(int i = 0; i < n; ++i)
            cnt[i] = i;
        for(int i = 1; i < n; ++i) {
            // odd extending
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j];
                ++j) {
                if(i - j == 0)
                    cnt[i + j] = 0;
                else
                    cnt[i + j] = min(cnt[i + j], cnt[i - j - 1] + 1);
            }
            // even extending
            for(int j = 0;
                i - j - 1 >= 0 && i + j < n && s[i - j - 1] == s[i + j]) {
                if(i - j - 1 == 0)
                    cnt[i + j] = 0;
                else
                    cnt[i + j] = min(cnt[i + j], cnt[i - j - 2] + 1);
            }
        }
        return cnt.back();
    }

  private:
};
