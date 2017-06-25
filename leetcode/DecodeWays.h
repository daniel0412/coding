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

class DecodeWays {
  public:
    int numDecodings(string s)
    {
        // corner case
        if(s.empty() || s[0] == '0')
            return 0;
        // return recursiveImpl(s, 0);
        return dpImpl(s);
    }

  private:
    // recursive solution runs too long
    int recursiveImpl(const string& s, int start)
    {
        // when one decoding found, return 1
        if(start >= s.size())
            return 1;
        if(s[start] == '0')
            return 0;
        int res = 0;
        res += recursiveImpl(s, start + 1);
        if(start + 1 < s.size()) {
            if(s[start] == '1' || (s[start] == '2' && s[start + 1] <= '6')) {
                res += recursiveImpl(s, start + 2);
            }
        }
        return res;
    }

    int dpImpl(const string& s)
    {
        vector<int> dp(s.size() + 1, 1);
        for(int i = 1; i < s.size(); ++i) {
            if(s[i-1] == '0') {
                dp[i+1] = (s[i] == '0') ? 0 : dp[i];
            }
            else {
                if(s[i] == '0') {
                    dp[i + 1] = s[i - 1] < '3' ? dp[i-1] : 0;
                }
                else {
                    if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                        dp[i + 1] = dp[i - 1] + dp[i];
                    }
                    else {
                        dp[i + 1] = dp[i];
                    }
                }
            }
        }
        return dp.back();
    }
};
