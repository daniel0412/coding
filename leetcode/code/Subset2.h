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

class Subset2 {
  public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > res;
        vector<int> path;
        // must sort first in order to deduplicte
        sort(nums.begin(), nums.end());
        helper(nums, 0, path, res);
        return res;
    }

  private:
    void helper(const vector<int>& nums,
                int start,
                vector<int>& path,
                vector<vector<int> >& res)
    {
        res.push_back(path);
        for(int i = start; i < nums.size(); ++i) {
            if(i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(nums, i + 1, path, res);
            path.pop_back();
        }
    }

    void dfsHelper(const vector<int>& nums,
                   int start,
                   vector<int>& path,
                   vector<vector<int> >& res)
    {
        if(start == nums.size()) {
            res.emplace_back(path);
            return;
        }
        dfsHelper(nums, start + 1, path, res);

        if(start == 0 || nums[start] != nums[start - 1]) {
            int i = 0;
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
            int cnt = i - start + 1;
            for(int j = 0; j < cnt; ++j) {
                path.push_back(nums[start]);
                dfsHelper(nums, start + j + 1, path, res);
            }
            path.resize(path.size() - cnt);
        }
    }
};
