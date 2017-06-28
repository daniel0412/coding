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

class RemoveDupFromSortedArray {
  public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() <= 1)
            return nums.size();
        int i = 0, j = 1;
        for(; j < nums.size(); ++j) {
            if(nums[j] != nums[i]) {
                swap(nums[j], nums[++i]);
            }
        }
        return ++i;
    }

  private:
};
