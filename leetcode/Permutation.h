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

class Permutation {
  public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > res;
        if(nums.empty())
            return res;
        // sol 1) swap recursion
        // swapPermutateImpl(nums, 0, res);

        // sol 2) dfs recursion
        vector<bool> used(nums.size(), false);
        vector<int> path;
        dfsImpl(nums, path, used, res);
        return res;
    }

  private:
    void swapPermutateImpl(vector<int>& nums,
                           int start,
                           vector<vector<int> >& res)
    {
        if(start == nums.size() - 1) {
            res.emplace_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            swapPermutateImpl(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }

    void dfsImpl(const vector<int>& nums,
                 vector<int>& path,
                 vector<bool>& used,
                 vector<vector<int> >& res)
    {
        if(path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i])
                continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            dfsImpl(nums, path, used, res);
            path.pop_back();
            used[i] = false;
        }
    }
};
