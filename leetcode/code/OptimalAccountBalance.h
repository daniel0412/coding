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

class OptimalAccountBalance {
  public:
    int minTransfers(vector<vector<int> >& transactions)
    {
        unordered_map<int, int> m;
        for(auto& t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> amt;
        for(const auto& kv : m) {
            if(kv.second)
                amt.emplace_back(kv.second);
        }
        if(amt.empty())
            return 0;
        int cnt = 0;
        return dfs(amt, 0, cnt);
    }

    int dfs(vector<int>& amt, int start, int& cnt)
    {
        int res = numeric_limits<int>::max();
        while(start < amt.size() && amt[start] == 0)
            ++start;
        for(int i = start + 1; i < amt.size(); ++i) {
            if(amt[start] * amt[i] < 0) {
                ++cnt;
                amt[i] += amt[start];
                res = min(res, dfs(amt, start + 1, cnt));
                amt[i] -= amt[start];
            }
        }
        return res == numeric_limit<int>::max() ? cnt : res;
    }

  private:
};
