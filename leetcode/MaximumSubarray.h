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

class MaximumSubarray {
  public:
      int maxSubArray(vector<int>& nums) {
          int maxSum = INT_MIN;
          if(nums.empty()) return maxSum;
          int prevSum = INT_MIN;
          for(size_t i = 0; i < nums.size(); ++i) {
              prevSum = prevSum > 0 ? prevSum + nums[i] : nums[i];
              maxSum = max(maxSum, prevSum);
          }
          return maxSum;
      }
  private:

};
