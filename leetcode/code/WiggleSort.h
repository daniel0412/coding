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

class WiggleSort {
  public:
    void wiggleSort(vector<int>& nums)
    {
        if(nums.size() < 2)
            return;
        for(size_t i = 1; i < nums.size(); ++i) {
            if((i % 2 == 1 && nums[i] < nums[i - 1]) ||
               (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }

  private:
};
