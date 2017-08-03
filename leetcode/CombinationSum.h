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

class CombinationSum {
  public:
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> res;
          vector<int> path;
          recursiveImpl(candidates, target, 0, path, res);
          return res;
      }

    private:
      void recursiveImpl(const vector<int>& candidates,
                         int target,
                         int start,
                         vector<int>& path,
                         vector<vector<int> >& res)
      {
          if(target < 0) return;
          for(int i = start; i < candidates.size(); ++i) {
              path.push_back(candidates[i]);
              int diff = target - candidates[i];
              if(diff == 0) {
                  res.emplace_back(path);
              }
              if(diff > 0) recursiveImpl(candidates, target - candidates[i], i, path, res);
              path.pop_back();
          }
      }
};
