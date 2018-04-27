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

class MoveZero {
  public:
    void moveZeroes(vector<int>& nums)
    {
        for(int i = 0, j = 0; j < nums.size(); ++j) {
            if(nums[i] == 0 && nums[j] != 0) {
                swap(nums[i++], nums[j]);
            }
            else if(nums[i] != 0) {
                ++i;
            }
        }
    }

  private:
};
