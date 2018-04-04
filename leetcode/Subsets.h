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

class Subsets {
  public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > res;
        vector<int> path;
        helper(nums, 0, path, res);
        return res;
    }

  private:
    // T(n) = T(n-1) + T(n-2) + ... + T(0) => O(2^n)
    // each call is O(n)
    // so in total O(n*2^n)
    void helper(const vector<int>& nums,
                int start,
                vector<int>& path,
                vector<vector<int> >& res)
    {
        res.push_back(path);
        for(int i = start; i < nums.size(); ++i) {
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
        path.push_back(nums[start]);
        dfsHelper(nums, start + 1, path, res);
        path.pop_back();
    }
};
