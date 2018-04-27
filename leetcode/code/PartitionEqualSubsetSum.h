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

class PartitionEqualSubsetSum {
  public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto n : nums) {
            for(int i = target; i >= n; --i) {
                dp[i] = dp[i] || dp[i - n];
            }
        }
        return dp.back();
    }

  private:
};
