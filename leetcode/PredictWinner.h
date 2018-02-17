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

class PredictWinner {
  public:
    bool PredictTheWinner(vector<int>& nums)
    {
        if(nums.empty())
            return false;
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1));
        dpimpl(nums, 0, nums.size() - 1, dp);
        return dp[0][nums.size() - 1] > 0;
    }

    int dpimpl(const vector<int>& nums, int s, int e, vector<vector<int> >& dp)
    {
        if(dp[s][e] == -1) {
            dp[s][e] =
                s == e ? nums[s] : max(nums[s] - dpimpl(nums, s + 1, e, dp),
                                       nums[e] - dpimpl(nums, s, e - 1, dp));
        }
        return dp[s][e];
    }

  private:
};
