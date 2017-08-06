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

class CombinationSumIV {
  public:
      int combinationSum4(vector<int>& nums, int target) {
          sort(nums.begin(), nums.end());
          vector<int> dp(nums.size()+1, 0);
          dp[0] = 1;
          for(int i = 1; i <= target; ++i) {
              for(auto v : nums) {
                  if(v > i) break;
                  dp[i] += dp[i-v];
              }
          }
          return dp.back();
      }
  private:
};
