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
};
