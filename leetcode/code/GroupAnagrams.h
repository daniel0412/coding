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

class GroupAnagrams {
  public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int id = 0;
        vector<vector<string>> res;
        unordered_map<string, size_t> m;
        for(auto s : strs) {
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()) {
                m.emplace(s, id++);
                res.push_back(vector<string>{s});
            }else{
                res[m[s]].emplace_back(s);
            }
        }
        return res;
    }

  private:
};
