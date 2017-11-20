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
        if(nums.empty())
            return res;
        impl(nums, 0, res);
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
};
