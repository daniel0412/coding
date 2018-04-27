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

class CombinationSumII {
  public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector<int> path;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path, res);
        return res;
    }

  private:
    void dfs(const vector<int>& candidates,
             int target,
             int start,
             vector<int>& path,
             vector<vector<int> >& res)
    {
        if(target < 0)
            return;
        if(target == 0)
            res.emplace_back(path);
        for(int i = start; i < candidates.size(); ++i) {
            if(i!=start && candidates[i] == candidates[i-1]) continue;
            int diff = target - candidates[i];
            if(diff < 0) break;
            path.push_back(candidates[i]);
            dfs(candidates, diff, i + 1, path, res);
            path.pop_back();
        }
    }
};
