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

class SingleElementInSortedArray {
  public:
    int singleNonDuplicate(vector<int>& nums)
    {
        if(nums.size() % 2 == 0)
            return 0;
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            if(start == end)
                return nums[start];
            int mid = start + (end - start) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            int leftsize = mid - start;
            int rightsize = end - mid;
            if(nums[mid] == nums[mid - 1]) {
                if((leftsize - 1) % 2 == 0) {
                    start = mid + 1;
                }
                else {
                    end = mid - 2;
                }
            }
            else if(nums[mid] == nums[mid + 1]) {
                if((rightsize - 1) % 2 == 0) {
                    end = mid - 1;
                }
                else {
                    start = mid + 2;
                }
            }
        }
        return 0;
    }

  private:
};
