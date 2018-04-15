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

class EncodeStrWithShortestLen {
  public:
    string encode(string s)
    {
        int n = s.size();
        vector<vector<string> > dp(n, vector<string>(n, ""));
        for(int l = n - 1; l >= 0; --l) {
            for(int r = l; r >= l; --r) {
                int len = r - l + 1;
                if(len <= 4) {
                    dp[l][r] = len;
                    continue;
                }
                for(int k = l; k < r; ++k) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
                string tmp = s.substr(l, len);
                string replace = "";
                size_t pos = (tmp + tmp).find(tmp, 1);
                if(pos < tmp.size()) {
                    size_t cnt = tmp.size() / (pos + 1);
                    replace = replace + stoi(cnt) + "[";
                    replace = replace + dp[l][l+pos-1] + "]";
                }
                else {
                    replace = tmp;
                }
                if(replace.size() < dp[l][r]) {
                    dp[l][r] = replace;
                }
            }
        }
	return dp[0][n-1];
    }

  private:
};
