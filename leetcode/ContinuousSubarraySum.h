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

class ContinuousSubarraySum {
  public:
      bool checkSubarraySum(vector<int>& nums, int k) {
          unordered_map<int, int> sumToIndex{{0,0}};
          int sum = 0;
          for(int i = 0; i < nums.size(); ++i) {
              sum += nums[i];
              if(sumToIndex.count(sum) == 0) {
                  sumToIndex[sum] = i;
              }
              int n = 1;
              while(sum >= n * k) {
                  int diff = sum - n * k;
                  if(sumToIndex.count(diff) && i > sumToIndex[diff]) {
                      return true;
                  }
                  ++n;
              }
          }
          return false;
      }
  private:
};
