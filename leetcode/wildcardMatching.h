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
    bool isMatch(std::string s, std::string p) { return greedySecondWrite(s, p); }

   private:
    /**
     * @brief: greedy implementation, pass the big data test
     *
     * @param s
     * @param p
     *
     * @return
     */
    bool greedyImpl(const std::string& s, const std::string& p) {
        int si = 0, pi = 0, sLen = s.length(), pLen = p.length();
        int startSI = 0, matchPI = -1;

        while (si < sLen) {
            if (pi < pLen && (p[pi] == '?' || p[pi] == s[si])) {
                ++si;
                ++pi;
            } else if (pi < pLen && p[pi] == '*') {
                startSI = si;
                matchPI = ++pi;
            } else if (matchPI > -1) {
                si = ++startSI;
                pi = matchPI;
            } else {
                return false;
            }
        }
        while (pi < pLen) {
            if (p[pi++] != '*') return false;
        }
        return true;
    }

    bool greedySecondWrite(const std::string& s, const string& p)
    {
        int sLen = s.size(), pLen = p.size();
        int si = 0, pi = 0;
        int sStartId = 0, pMatchedId = -1;
        while(si < sLen) {
            if(pi < pLen && (p[pi] == '?' || p[pi] ==  s[si])){
                ++si;
                ++pi;
            }else if(pi < pLen && p[pi] == '*') {
                sStartId = si;
                pMatchedId = ++pi;
            }else if (pMatchedId > -1) {
                si = ++sStartId;
                pi = pMatchedId;
            }else {
                return false;
            }
        }
        while(pi < pLen) {
            if(p[pi++] != '*') return false;
        }
        return true;
    }

    /**
     * @brief:  dp implementation, O(m*n) space complexity and O(m*n) time
     *complexity
     *          fails the big data test
     *
     * @param s
     * @param p
     *
     * @return
     */
    bool dpImpl(const string& s, const string& p) {
        int sLen = s.length(), pLen = p.length();

        vector<vector<bool> > flags(sLen + 1, vector<bool>(pLen + 1, false));
        for (int si = 0; si <= sLen; ++si) {
            for (int pi = 0; pi <= pLen; ++pi) {
                if (si == 0) {
                    flags[0][pi] =
                        (pi == 0 ? true : flags[0][pi - 1] && p[pi] == '*');
                    continue;
                }
                if (pi == 0) {
                    flags[si][0] = (si == 0 ? true : p[0] == '*');
                    continue;
                }

                if (p[pi] == s[si] || p[pi] == '?') {
                    flags[si][pi] = flags[si - 1][pi - 1];
                    continue;
                }

                if (p[pi] == '*') {
                    flags[si][pi] = flags[si - 1][pi] || flags[si][pi - 1];
                    continue;
                }
            }
        }
        return flags[sLen][pLen];
    }
};
