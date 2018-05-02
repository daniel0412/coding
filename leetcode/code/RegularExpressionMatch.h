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

class RegularExpressionMatch {
  public:
    bool isMatch(string s, string p) { return dpImpl(s, p); }

  private:
    // slow
    bool recursiveImpl(const string s, const string p)
    {
        if(p.empty())
            return s.empty();
        if(p.size() > 1 && p[1] == '*') {
            return recursiveImpl(s, p.substr(2)) ||
                (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
                 recursiveImpl(s.substr(1), p));
        }
        else {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') &&
                recursiveImpl(s.substr(1), p.substr(1));
        }
    }
    // fast dp implementation
    bool dpImpl(const string s, const string p)
    {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool> > dp(sLen + 1, vector<bool>(pLen + 1, false));
        dp[0][0] = true;
        // initial condition to process p="a*b*c*" cases
        for(int pi = 1; pi <= pLen; ++pi) {
            dp[0][pi] = pi > 1 && dp[0][pi - 2] && p[pi - 1] == '*';
        }
        for(int si = 1; si <= sLen; ++si) {
            for(int pi = 1; pi <= pLen; ++pi) {
                if(p[pi - 1] == '*') {
                    // 1. c* matches zero occurence
                    // 2. (si-1, pi) matches, and c* also matches
                    dp[si][pi] = dp[si][pi - 2] ||
                        ((s[si - 1] == p[pi - 2] || p[pi - 2] == '.') &&
                         dp[si - 1][pi]);
                }
                else {
                    dp[si][pi] = dp[si - 1][pi - 1] &&
                        (s[si - 1] == p[pi - 1] || p[pi - 1] == '.');
                }
            }
        }
        return dp[sLen][pLen];
    }
};
