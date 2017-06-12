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

class MaxSizeSubarraySumEqualsK {
  public:
      int maxSubArrayLen(vector<int>& nums, int k) {
          unordered_map<int, int> sumToIndex;
          int maxLen = 0;
          int sum = 0;
          for(int i = 0; i < nums.size(); ++i) {
              sum += nums[i];
              if(sumToIndex.count(sum) == 0) {
                  sumToIndex[sum] = i;
              }
              int diff = sum - k;
              if(diff == 0) maxLen = i + 1;
              else if(sumToIndex.count(diff)) {
                  maxLen = max(maxLen, (i-sumToIndex[diff]));
              }
          }
          return maxLen;

      }
  private:
};
