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

class SearchInRotatedSortedArrayII {
  public:
    bool search(vector<int>& nums, int target)
    {
        if(nums.empty())
            return false;
        int s = 0, e = nums.size() - 1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(nums[m] == target)
                return true;
            else {
                // m->e is sorted
                if(nums[m] < nums[e]) {
                    if(target > nums[m] && target <= nums[e]) {
                        s = m + 1;
                    }
                    else {
                        e = m - 1;
                    }
                }
                // s->m is sorted
                else if(nums[m] > nums[e]) {
                    if(target < nums[m] && target >= nums[s]) {
                        e = m - 1;
                    }
                    else {
                        s = m + 1;
                    }
                }
                // not sure which side is sorted
                else {
                    --e;
                }
            }
        }
        return false;
    }

  private:
};
