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

class ThreeSumCloest {
  public:
      int threeSumClosest(vector<int>& nums, int target) {
          sort(nums.begin(), nums.end());
          int minDiff = INT_MAX;
          int cloestSum = 0;
          for(int a = 0; a < nums.size() - 2; ++a) {
              if(a > 0 && nums[a] == nums[a-1]) {
                  continue;
              }
              int b = a +1, c = nums.size() - 1;
              while(b < c) {
                  if(b > a + 1 && nums[b] == nums[b-1]) {
                      ++b;
                      continue;
                  }
                  int sum = nums[a] + nums[b] + nums[c];
                  int diff = abs(sum - target);
                  if(diff < minDiff) {
                      cloestSum = sum;
                      minDiff = diff;
                  }
                  if(sum == target) {
                      return target;
                  }else if(sum < target) {
                      ++b;
                  }else{
                      --c;
                  }
              }
          }
          return cloestSum;
      }
  private:
};
