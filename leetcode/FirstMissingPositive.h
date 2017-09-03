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

class FirstMissingPositive {
  public:
    int firstMissingPositive(vector<int>& nums)
    {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i++] = 0;
                continue;
            }
            if(nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) {
                ++i;
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
        i = 0;
        while(i < nums.size()) {
            if(nums[i] != i + 1)
                break;
            else
                ++i;
        }
        return i + 1;
    }

  private:
};
