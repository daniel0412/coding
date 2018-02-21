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

class PermutationII {
  public:
    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        vector<vector<int> > res;
        // swap impl
        impl(nums, 0, res);
        // dfs impl
        //unordered_map<int, int> m;
        //for(auto n : nums)
            //++m[n];
        //sort(nums.begin(), nums.end());
        //vector<int> path;
        //dfs(nums, m, path, res);
        return res;
    }

  private:
    void impl(vector<int>& nums, int start, vector<vector<int> >& res)
    {
        if(start == nums.size() - 1) {
            res.emplace_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); ++i) {
            if(i > start && nums[i] == nums[start])
                continue;
            swap(nums[i], nums[start]);
            impl(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }

    void dfs(const vector<int>& nums,
             unordered_map<int, int>& m,
             vector<int>& path,
             vector<vector<int> >& res)
    {
        if(path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            if(m[nums[i]] == 0)
                continue;
            --m[nums[i]];
            path.emplace_back(nums[i]);
            dfs(nums, m, path, res);
            path.pop_back();
            ++m[nums[i]];
        }
    }
};
