/* 44. Wildcard Matching
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class WildcardMatching {
  public:
    bool isMatch(std::string s, std::string p) { return greedy(s, p); }

  private:
    // exponential time complexity, timeout
    bool recursive(string s, string p)
    {
        // check corner case, make sure both strings are not empty
        if(p.empty())
            return s.empty();
        if(s.empty())
            return p.find_first_not_of('*') == string::npos;

        if(s.front() == p.front() || p.front() == '?') {
            return recursive(s.substr(1), p.substr(1));
        }
        else if(p.front() == '*') {
            return recursive(s, p.substr(1)) || recursive(s.substr(1), p);
        }
        else {
            return false;
        }
    }

    bool greedy(const std::string& s, const string& p)
    {
        int sLen = s.size(), pLen = p.size();
        int si = 0, pi = 0;
        // index for s and p to go back when failed to match
        int sStartId = -1, pMatchedId = -1;
        // ATTENTION: here only use len of s, since it is possible that pi ==
        // p.size(), then we should go back to pmatchedId
        while(si < sLen) {
            if(pi < pLen && (p[pi] == '?' || p[pi] == s[si])) {
                ++si;
                ++pi;
            }
            // when * met, assume s[si] not matched, ignore pi and check next
            // char in p
            else if(pi < pLen && p[pi] == '*') {
                sStartId = si;
                pMatchedId = ++pi;
            }
            // match failed: 1) current char does not match or 2) p ends
            // earlier than s
            // skip sStart, treat it as matched with *
            else if(pMatchedId > -1) {
                si = ++sStartId;
                pi = pMatchedId;
            }
            else {
                return false;
            }
        }
        // make sure extra chars in p are all *
        if(pi < pLen)
            return p.substr(pi).find_first_not_of('*') == string::npos;
        // if s and p exactly matches
        return true;
    }

    bool dpImpl(const string& s, const string& p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        // initialization: s empty, to match all p up to the first non-*
        // p empty, s not empty, should be false
        dp[0][0] = true;
        for(int j = 1; j <= n; ++j) {
            if(p[j - 1] != '*')
                break;
            dp[0][j] = true;
        }

        // O(M*N)
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] &&
                        (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
