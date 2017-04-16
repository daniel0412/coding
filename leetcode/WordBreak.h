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
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); ++i) {
            for(int end = 0; end < i; ++end) {
                if(dp[end + 1] && dict.count(s.substr(end + 1, i - end)) > 0) {
                    dp[i + 1] = true;
                    break;
                }
            }
            if(!dp[i + 1]) {
                dp[i + 1] = dict.count(s.substr(0, i + 1)) > 0;
            }
        }
        return dp[s.size()];
    }

  private:
};
