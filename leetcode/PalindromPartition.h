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

class PalindromPartition {
  public:
    vector<vector<string> > partition(string s)
    {
        vector<string> path;
        vector<vector<string> > res;
        helper(s, 0, path, res);
        return res;
    }

  private:
    void helper(const string& s,
                int start,
                vector<string>& path,
                vector<vector<string> >& res)
    {
        if(start >= (int) s.size()) {
            res.emplace_back(path);
        }
        for(int i = start; i < (int) s.size(); ++i) {
            if(isPalindrome(s, start, i)) {
                path.emplace_back(s.substr(start, i - start + 1));
                helper(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int i, int j)
    {
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
