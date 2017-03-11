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

class Solution {
   public:
    bool isMatch(std::string s, std::string p) { return impl1(s, p); }

   private:
    bool impl1(const std::string& s, const std::string& p) {
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
};
