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

class RestoreIpAddress {
  public:
    vector<string> restoreIpAddresses(string s)
    {
        string path;
        vector<string> res;
        helper(s, 0, 0, path, res);
        return res;
    }

  private:
    void helper(
        const string& s, int i, int cnt, string& path, vector<string>& res)
    {
        if(i >= s.size() || cnt == 4) {
            if(path.size() == s.size() + 4) {
                res.emplace_back(path.substr(1));
            }
            return;
        }

        for(int j = 1; j <= 3 && i + j <= s.size(); ++j) {
            // allow 0.0.0.0, but we do not allow '012'
            if(j > 1 && s[i] == '0')
                break;
            // do not allow greater than 255
            if(stoi(s.substr(i, j)) > 255)
                break;
            path = path + "." + s.substr(i, j);
            helper(s, i + j, cnt + 1, path, res);
            path = path.substr(0, path.size() - j - 1);
        }
    }
};
