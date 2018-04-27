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

class LongestPalindromicSubstr {
  public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int maxLen = 0, start = 0;
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
                if(dp[i][j]) {
                    int tmpLen = j - i + 1;
                    if(tmpLen > maxLen) {
                        maxLen = tmpLen;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }

    string fasterImpl(string s)
    {
        int maxLen = 0, start = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            int j = i, k = i;
            while(j > 0 && k < n-1 && s[j-1] == s[k+1]) {
                --j;
                ++k;
            }
            int tmpLen = k-j+1;
            if(tmpLen > maxLen) {
                maxLen = tmpLen;
                start = j;
            }
            j = i, k = i+1;
            if(k < n && s[j]==s[k]) {
                while(j > 0 && k < n-1 && s[j-1]==s[k+1]) {
                    --j;
                    ++k;
                }
                tmpLen = k-j+1;
                if(tmpLen > maxLen) {
                    maxLen = tmpLen;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLen);
    }

  private:
};
