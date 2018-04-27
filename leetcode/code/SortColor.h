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

class SortColor {
  public:
      void sortColors(vector<int>& nums) {
          if(nums.size() <= 1) return;
          int m = 0, n = nums.size() - 1, i = 0;
          while(i <= n) {
              while(m < nums.size() && nums[m] == 0) {
                  ++m;
                  i = m;
              }
              while(n >= 0 && nums[n] == 2) {
                  --n;
              }
              if(n <= m) return;
              if(nums[i] == 0) {
                  swap(nums[m++], nums[i]);
              }else if(nums[i] == 2){
                  swap(nums[n--], nums[i]);
              }else{
                  ++i;
              }
          }
      }
  private:
};
