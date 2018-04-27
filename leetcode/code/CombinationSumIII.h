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

class CombinationSumIII {
  public:
      vector<vector<int>> combinationSum3(int k, int n) {
          vector<vector<int>> res;
          vector<int> path;
          dfs(k, n, 1, path, res);
          return res;
      }
  private:
    void dfs(const int k,
             int n,
             int start,
             vector<int>& path,
             vector<vector<int> >& res)
    {
        if(n == 0 && path.size() == k) {
            res.emplace_back(path);
            return;
        }
        if(path.size() >= k) return;
        for(int i = start; i <=9; ++i) {
            int diff = n - i;
            if(diff < 0) return;
            path.push_back(i);
            dfs(k, n-i, i+1, path, res);
            path.pop_back();
        }
    }
};
