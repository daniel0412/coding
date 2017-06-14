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

class RemoveInvalidParentheses {
  public:
    vector<string> removeInvalidParentheses(string s)
    {
        int left = 0, right = 0, pair = 0;
        // cout number of left/right parenthese to remove
        for(auto& c : s) {
            if(c == '(') {
                ++left;
            }
            else if(c == ')') {
                if(left > 0) {
                    --left;
                }
                else {
                    ++right;
                }
            }
        }
        unordered_set<string> res;
        dfs(s, 0, left, right, pair, "", res);
        return vector<string>(res.begin(), res.end());
    }

  private:
    void dfs(const string& s,
             int start,
             int left,
             int right,
             int pair,
             string path,
             unordered_set<string>& res)
    {
        if(left < 0 || right < 0 || pair < 0)
            return;
        if(start == s.size()) {
            if(left == 0 && right == 0 && pair == 0) {
                res.insert(path);
            }
            return;
        }
        char c = s[start];

        if(c == '(') {
            // deduplication
            if(start == 0 || c != s[start-1]) {
                for(int i = start; i < s.size() && c==s[i]; ++i) {
                    dfs(s, i+1, left - 1 - i + start, right, pair, path, res);
                }
            }
            path.push_back(c);
            dfs(s, start + 1, left, right, pair + 1, path, res);
        }
        else if(c == ')') {
            // deduplication
            if(start == 0 || c != s[start-1]) {
                for(int i = start; i < s.size() && c==s[i]; ++i) {
                    dfs(s, i+1, left, right - 1 - i + start, pair, path, res);
                }
            }

            //dfs(s, start + 1, left, right - 1, pair, path, res);
            path.push_back(c);
            dfs(s, start + 1, left, right, pair - 1, path, res);
        }
        else {
            path.push_back(c);
            dfs(s, start + 1, left, right, pair, path, res);
        }
    }
};
