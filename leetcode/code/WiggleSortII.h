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

class WiggleSortII {
  public:
      void wiggleSort(vector<int>& nums) {
          vector<int> sorted(nums);
          sort(sorted.begin(), sorted.end());
          // i set to be this val: since if starts from 0, then in the middle, 
          // we might get two equal numbers [1,1,2,2,3,3]
          int i = (nums.size()-1)/2, j = sorted.size()-1;
          for(size_t k = 0; k < nums.size(); ++k) {
              nums[k] = sorted[i&1 ? j--:i--];
          }
      }
  private:
};
