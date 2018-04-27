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

class FindMinInRotatedSortedArrayII {
  public:
    int findMin(vector<int>& nums)
    {
        int s = 0, e = nums.size() - 1;
        int minV = numeric_limits<int>::max();
        while(s <= e) {
            if(nums[s] < nums[e]) {
                minV = min(minV, nums[s]);
                return minV;
            }

            int m = s + (e - s) / 2;
            minV = min(minV, nums[m]);
            if(nums[m] < nums[e]) {
                e = m - 1;
            }
            else if(nums[m] > nums[e]) {
                s = m + 1;
            }
            else {
                --e;
            }
        }
        return minV;
    }


  private:
};
