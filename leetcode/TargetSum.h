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

class TargetSum {
  public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        if(nums.empty())
            return S == 0;
        return recursiveImpl(nums, S, 0);
    }

  private:
    int recursiveImpl(const vector<int>& nums, int target, int i)
    {
        int len = nums.size();
        if(i == len - 1) {
            int cnt = 0;
            cnt += (target == nums[i]);
            cnt += (target == -nums[i]);
            return cnt;
        }
        else {
            return recursiveImpl(nums, target - nums[i], i + 1) +
                recursiveImpl(nums, target + nums[i], i + 1);
        }
    }
};
