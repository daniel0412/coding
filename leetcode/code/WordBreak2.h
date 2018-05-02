/* 140. Word Break II
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 *non-empty words, add spaces in s to construct a sentence where each word is a
 *valid dictionary word. You may assume the dictionary does not contain
 *duplicate words.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
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
#include <algorithm>
#include <utility>

using namespace std;

class WordBreak2 {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // starting from any index, next word can only be of length within this
        // range
        size_t minl = s.size(), maxl = 0;
        for(const auto& w : wordDict) {
            minl = min(minl, w.size());
            maxl = max(maxl, w.size());
        }
        // dp[i]: from i->n, it is breakable or not memorization
        // initially we treat all breakable to force we do the dfs
        // later if it is false, we know it will fail so prune
        vector<bool> dp(s.size() + 1, true);
        vector<string> res;
        string path;
        dfs(s, dict, 0, minl, maxl, dp, path, res);
        return res;
    }
    void dfs(const string& s,
             unordered_set<string>& dict,
             int start,
             const size_t minl,
             const size_t maxl,
             vector<bool>& dp,
             string& path,
             vector<string>& res)
    {
        if(start >= s.size())
            return;
        // from start, just try all possible length that might form a word in dict
        for(int i = start + minl - 1; i < s.size() && i < start + maxl; ++i) {
            string sub = s.substr(start, i - start + 1);
            // substring is in the dict, as well as the following substring is breakable
            if(dp[i+1] && dict.count(sub)) {
                if(i == s.size() - 1) {
                    res.emplace_back(path + sub);
                }
                else {
                    // check result size before
                    int oldsize = res.size();
                    path = path + sub + " ";
                    dfs(s, dict, i + 1, minl, maxl, dp, path, res);
                    // if result size not changed, means not breakable from i
                    // to n
                    if(oldsize == res.size())
                        dp[i+1] = false;
                    path = path.substr(0, path.size() - sub.size() - 1);
                }
            }
        }
    }
};
