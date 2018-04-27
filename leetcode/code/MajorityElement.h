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

class MajorityElement {
  public:
      int majorityElement(vector<int>& nums) {
          int x = -1, cnt = 0;
          int i = 0;
          while(i < nums.size()) {
              if(cnt == 0) {
                  x = nums[i];
                  cnt = 1;
              }else {
                  cnt = x == nums[i] ? cnt + 1 : cnt - 1;
              }
              ++i;
          }
          return x;
      }
  private:
};
