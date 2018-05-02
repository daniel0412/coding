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
            return true;
        return dpImpl(nums);
        // return scoreDiff(nums, 0, nums.size() - 1) >= 0;
    }

    // recursive implementation
    // each call: get the max score diff in the range [r, l]
    int scoreDiff(const vector<int>& nums, int l, int r)
    {
        // only one elements, current player will always get this score
        if(l == r)
            return nums[l];
        // use the one choose l/r, decrease it by max diff score can get for
        // the next player
        return max(nums[l] - scoreDiff(nums, l + 1, r),
                   nums[r] - scoreDiff(nums, l, r - 1));
    }

    // easily converted to dp
    bool dpImpl(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int l = n - 1; l >= 0; --l) {
            for(int r = l; r < n; ++r) {
                if(l == r)
                    dp[l][r] = nums[l];
                else
                    dp[l][r] =
                        max(nums[l] - dp[l + 1][r], nums[r] - dp[l][r - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }

  private:
};
