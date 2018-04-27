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

class RemoveDupFromSortedArrayII {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() <= 2)
            return nums.size();
        int i = 1, j = 2;
        for(; j < nums.size(); ++j) {
            if(nums[j] == nums[i] && nums[i - 1] == nums[i]) {
                continue;
            }
            else {
                swap(nums[j], nums[++i]);
            }
        }
        return ++i;
    }


  private:
};
