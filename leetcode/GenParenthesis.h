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

class GenParenthesis {
  public:
    vector<string> generateParenthesis(int n) { return helper(n); }

  private:
    // dfs implementation
    // rules: left/right parenthesis number is n respectively
    // cannot have more right parenthesis than left parenthesis at any time
    void dfs(
        const int n, int left, int right, string& path, vector<string>& res)
    {
        if(path.size() == n * 2) {
            res.emplace_back(path);
            return;
        }
        if(left < n) {
            path.push_back('(');
            dfs(n, left + 1, right, path, res);
            path.pop_back();
        }
        if(right < left) {
            path.push_back(')');
            dfs(n, left, right + 1, path, res);
            path.pop_back();
        }
    }

    // generate parenthesis from n-1 to n (donot quite understand it)
    vector<string> helper(int n)
    {
        if(n <= 0)
            return vector<string>();
        unordered_set<string> res;
        res.insert("()");
        for(int i = 1; i < n; ++i) {
            unordered_set<string> tmp;
            for(auto s : res) {
                tmp.insert("()" + s);
                tmp.insert(s + "()");
                // the following line is wrong, should use a for loop
                // to take care of all cases
                // tmp.insert("(" + s + ")");
                for(int j = 0; j < s.size(); ++j) {
                    if(s[j] == '(') {
                        s.insert(s.begin() + j + 1, '(');
                        s.insert(s.begin() + j + 2, ')');
                        tmp.insert(s);
                        s.erase(s.begin() + j + 1, s.begin() + j + 3);
                    }
                }
            }
            res.clear();
            res.insert(tmp.begin(), tmp.end());
        }
        return vector<string>(res.begin(), res.end());
    }
};
