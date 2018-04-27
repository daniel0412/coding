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

class TargetSum {
  public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int cnt = 0;
        dfs(nums, S, 0, cnt);
        return cnt;
    }

    void dfs(const vector<int>& nums, int target, int i, int& cnt)
    {
        if(i == nums.size()) {
            if(target == 0)
                ++cnt;
            return;
        }
        dfs(nums, target + nums[i], i + 1, cnt);
        dfs(nums, target - nums[i], i + 1, cnt);
    }

    // use dp to cache number of path
    int findTargetSumWays(vector<int>& nums, int S)
    {
        // dp: cache at index i, the number of paths such that with given sum,
        // target can be achieved
        vector<unordered_map<int, int> > dp(nums.size());
        return dfs(nums, S, 0, dp);
    }
    int dfs(const vector<int>& nums,
            int target,
            int i,
            vector<unordered_map<int, int> >& dp)
    {
        if(i == nums.size())
            return target == 0;
        if(dp[i].count(target))
            return dp[i][target];
        int cnt1 = dfs(nums, target + nums[i], i + 1, dp);
        int cnt2 = dfs(nums, target - nums[i], i + 1, dp);
        dp[i][target] = cnt1 + cnt2;
        return dp[i][target];
    }
};
