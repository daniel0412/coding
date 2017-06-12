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

class MinSizeSubarraySum {
  public:
      int minSubArrayLen(int s, vector<int>& nums) {
          int left = 0, right = 0;
          int sum = 0;
          int minLen = INT_MAX;
          while(right < nums.size()) {
              sum += nums[right];
              if(sum >= s) {
                  while(sum - nums[left] >= s) {
                      ++left;
                      sum -= nums[left];
                  }
                  minLen = min(minLen, right - left + 1);
              }
              ++right;
          }
          return minLen == INT_MAX ? 0 : minLen;
      }
  private:
};
