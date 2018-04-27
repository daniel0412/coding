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

class LetterCombination {
  public:
    vector<string> letterCombinations(string digits)
    {
        d_map.insert({'2', "abc"});
        d_map.insert({'3', "def"});
        d_map.insert({'4', "ghi"});
        d_map.insert({'5', "jkl"});
        d_map.insert({'6', "mno"});
        d_map.insert({'7', "pqrs"});
        d_map.insert({'8', "tuv"});
        d_map.insert({'9', "wxyz"});
        vector<string> res;

        if(validStr(digits)) {
            string path;
            dfs(digits, 0, path, res);
        }
        return res;
    }

  private:
    unordered_map<char, string> d_map;

    bool validStr(const string& digits)
    {
        if(digits.size() == 0)
            return false;
        for(auto c : digits) {
            if(d_map.find(c) == d_map.end())
                return false;
        }
        return true;
    }
    void dfs(const string& s, int start, string& path, vector<string>& res)
    {
        if(start == s.size()) {
            res.push_back(path);
            return;
        }
        char digit = s[start];
        string mappedStr = d_map[digit];
        for(auto c : mappedStr) {
            path.push_back(c);
            dfs(s, start + 1, path, res);
            path.pop_back();
        }
    }
};
