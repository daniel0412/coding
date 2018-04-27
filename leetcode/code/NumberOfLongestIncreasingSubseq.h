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

class NumberOfLongestIncreasingSubseq {
  public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int maxlen = 1;
        // track len of increasing subsequency ending at index i
        vector<int> dp(nums.size(), 1);
        // track number of longest increasing subseq ending at index i
        vector<int> cnt(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] = dp[j]) {
                        cnt[i] += cnt[j];
                    }
                }
                maxlen = max(maxlen, dp[i]);
            }
        }
        int maxcnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(dp[i] == maxlen)
                maxcnt += cnt[i];
        }
        return maxcnt;
    }

  private:
};
