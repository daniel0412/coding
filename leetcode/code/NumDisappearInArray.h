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

class NumDisappearInArray {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> res;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) {
                ++i;
                continue;
            }
            else {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1)
                res.push_back(i + 1);
        }
        return res;
    }

  private:
};
