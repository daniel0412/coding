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

class GroupShiftedStrs {
  public:
    vector<vector<string> > groupStrings(vector<string>& strings)
    {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > m;
        for(const auto& s : strings) {
            string t;
            for(const auto& c : s) {
                t += to_string((c + 26 - s[0]) % 26) + ",";
            }
            m[t].emplace_back(s);
        }
        for(const auto& kv : m) {
            res.emplace_back(kv.second);
        }
        return res;
    }

  private:
};
