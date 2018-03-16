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
}
;
