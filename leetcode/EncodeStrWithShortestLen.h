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
        // template for loop when cut in the middle is needed
        for(int l = n - 1; l >= 0; --l) {
            for(int r = l; r < n; ++r) {
                dp[l][r] = s.substr(l, len);
                int len = r - l + 1;
                if(len <= 4) {
                    continue;
                }
                // first check if length is shorter by use two substring
                // encoding
                for(int k = l; k < r; ++k) {
                    if(dp[l][r].size() > dp[l][k].size() + dp[k + 1][r].size())
                        dp[l][r] = dp[l][k] + dp[k + 1][r];
                }
                // then check if length is shorter by encoding the whole
                // substring
                string tmp = s.substr(l, len);
                string replace = "";
                size_t pos = (tmp + tmp).find(tmp, 1);
                if(pos < tmp.size()) {
                    size_t cnt = tmp.size() / pos;
                    // ATTENTION: here we should always use results from dp
                    // cache
                    replace = to_string(cnt) + "[" + dp[l][l + pos - 1] + "]";
                }
                else {
                    replace = tmp;
                }
                if(replace.size() < dp[l][r].size()) {
                    dp[l][r] = replace;
                }
            }
        }
        return dp[0][n - 1];
    }

  private:
};
