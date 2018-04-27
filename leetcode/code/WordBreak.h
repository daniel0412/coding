/* 139. Word Break
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 *non-empty words, determine if s can be segmented into a space-separated
 *sequence of one or more dictionary words. You may assume the dictionary does
 *not contain duplicate words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
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
#include <queue>
#include <functional>
#include <utility>

using namespace std;

class WordBreak {
  public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        return dpImpl(s, wordDict);
        // unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // return recursiveImpl(s, dict, 0);
    }

  private:
    bool dpImpl(const string& s, const vector<string>& wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); ++i) {
            for(int breakPos = 0; breakPos < i; ++breakPos) {
                if(dp[breakPos + 1] &&
                   dict.count(s.substr(breakPos + 1, i - breakPos)) > 0) {
                    dp[i + 1] = true;
                    break;
                }
            }
            if(!dp[i + 1] && dict.count(s.substr(0, i + 1)) > 0) {
                dp[i + 1] = true;
            }
        }
        return dp.back();
    }

    bool recursiveImpl(const string& s,
                       const unordered_set<string>& dict,
                       int breakPos)
    {
        if(breakPos == s.size())
            return true;
        for(int i = breakPos; i < s.size(); ++i) {
            if(dict.count(s.substr(breakPos, i - breakPos + 1)) > 0) {
                if(recursiveImpl(s, dict, i + 1))
                    return true;
            }
        }
        return false;
    }
};
