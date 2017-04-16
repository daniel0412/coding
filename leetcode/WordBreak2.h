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
        d_minWordLen = INT_MAX;
        d_maxWordLen = INT_MIN;
        for(const auto& w : wordDict) {
            d_minWordLen = d_minWordLen > (int)w.size() ? w.size() : d_minWordLen;
            d_maxWordLen = d_maxWordLen > (int)w.size() ? d_maxWordLen : w.size();
        }
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_set<string> res;
        vector<bool> flags(s.size() + 1, true);
        flags[0] = true;
        vector<string> path;
        dfsImpl(s, dict, flags, 0, path, res);
        return vector<string>(res.begin(), res.end());
    }

  private:
    int d_minWordLen;
    int d_maxWordLen;
    void dfsImpl(const string& s,
                 const unordered_set<string>& dict,
                 vector<bool>& flags,
                 int start,
                 vector<string>& path,
                 unordered_set<string>& res)
    {
        if(start == s.size()) {
            ostringstream ss;
            copy(path.begin(), path.end()-1, ostream_iterator<string>(ss, " "));
            ss << *path.rbegin();
            res.insert(ss.str());
            return;
        }

        for(int i = start + d_minWordLen - 1;
            i < s.size() && i < start + d_maxWordLen;
            ++i) {
            string tmp(s.substr(start, i - start + 1));
            if(dict.count(tmp) > 0 && flags[i + 1]) {
                int oldResSize = res.size();
                path.push_back(tmp);
                dfsImpl(s, dict, flags, i + 1, path, res);
                if(oldResSize == res.size())
                    flags[i + 1] = false;
                path.pop_back();
            }
        }
    }
};
