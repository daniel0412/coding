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

    /* ---- below are first round implementation, but hard to undersatnd --- */
    bool PredictTheWinner(vector<int>& nums)
    {
        if(nums.empty())
            return false;
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1));
        dpimpl(nums, 0, nums.size() - 1, dp);
        return dp[0][nums.size() - 1] >= 0;
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


    // recursive implementation
    bool PredictTheWinner(vector<int>& nums)
    {
        // TODO: why empty, player 1 wins
        if(nums.empty())
            return true;
        return canWin(nums, 0, nums.size() - 1, 1, 0, 0);
    }

    // this canwin function does not care about who is the player
    // only care if the passed in player can win or not
    bool canWin(const vector<int>& nums, int si, int ei, int p, int s1, int s2)
    {
        if(p == 1) {
            // player 1 wins if greater and equal
            if(si == ei)
                return s1 + nums[si] >= s2;
            return !canWin(nums, si + 1, ei, 2, s1 + nums[si], s2) ||
                !canWin(nums, si, ei - 1, 2, s1 + nums[ei], s2);
        }
        else {
            // player 2 wins only if greater ?????
            if(si == ei)
                return s1 < s2 + nums[si];
            return !canWin(nums, si + 1, ei, 1, s1, s2 + nums[si]) ||
                !canWin(nums, si, ei - 1, 1, s1, s2 + nums[ei]);
        }
    }

  private:
};
