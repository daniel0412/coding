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

class LongestIncreasingSubseq {
  public:
    // O(n*lgn) implementation with constructing the matrix
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> res;
        for(auto n : nums) {
            auto iter = lower_bound(res.begin(), res.end(), n);
            if(iter == res.end())
                res.push_back(n);
            else
                *iter = n;
        }
        return res.size();
    }


    // O(n^2) dp implementation
    int dp(vector<int>& nums)
    {
        if(nums.size() < 2)
            return nums.size();
        int maxlen = 1;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    if(dp[i] < dp[j] + 1) {
                        dp = dp[j] + 1;
                    }
                }
                maxlen = max(maxlen, dp[i]);
            }
        }
        return maxlen
    }


  private:
};
