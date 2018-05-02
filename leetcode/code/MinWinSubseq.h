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

class MinWinSubseq {
  public:
    string minWindow(string s, string t)
    {
        if(t.size() > s.size() || t.empty())
            return "";
    }

    // o(s*t) dp solution
    // dp[i][j]: starting index of s, such that from this index, we can find a
    // shortest subseq in s[0-j] for t[0-i]
    string dp(const stirng& s, const string& t)
    {
        int m = t.size(), n = s.size();
        vector<vector<int> > dp(m, vector<int>(n, -1));
        // initialize for t[0]
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == t[0])
                dp[0][i] = i;
        }

        // update the information for different [i,j]
        for(int i = 1; i < m; ++i) {
            int start = -1;
            for(int j = 0; j < n; ++j) {
                if(t[i] == s[j])
                    dp[i][j] = start;
                if(dp[i - 1][j] != -1)
                    start = dp[i - 1][j];
            }
        }

        // collect the minimum window string
        int minlen = numeric_limits<int>::max();
        string minStr;
        for(int i = 0; i < n; ++i) {
            if(dp[m - 1][i] != -1) {
                int tmplen = i - dp[m - 1][i];
                if(tmplen < minlen) {
                    minlen = tmplen;
                    minStr = s.sub(dp[m - 1][i], minlen);
                }
            }
            return minStr;
        }
    }

    // O(s^2)
    string bruteforce(const string& s, const string& t)
    {
        int minlen = numeric_limits<int>::max();
        string minstr;
        for(int i = 0; i + t.size() <= s.size(); ++i) {
            if(s[i] == t[0]) {
                int tmplen = exist(s, i, t);
                if(tmplen != -1) {
                    if(tmplen < minlen) {
                        minlen = tmplen;
                        minstr = s.sub(i, tmplen);
                    }
                }
            }
        }
        return minstr;
    }

    // return the end index of s which include t as a subseq
    int exist(const string& s, const int i, const string& t)
    {
        int end = i, j = 0;
        while(end < s.size()) {
            if(s[end++] == t[j]) {
                ++j;
            }
            if(j == t.size()) {
                return (end - i);
            }
        }
        return -1;
    }

  private:
};
