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

class PredictWinner {
  public:
    bool PredictTheWinner(vector<int>& nums)
    {
        if(nums.empty())
            return false;
        return recursiveImpl(nums, 0, nums.size() - 1, 0, 0, 1);
    }

    bool recursiveImpl(
        const vector<int>& nums, int s, int e, int sum1, int sum2, int player)
    {
        if(s > e)
            return sum1 > sum2;
        return player == 1 ?
            (recursiveImpl(nums, s + 1, e, sum1 + nums[s], sum2, 2) ||
             recursiveImpl(nums, s, e - 1, sum1 + nums[e], sum2, 2)) :
            (recursiveImpl(nums, s + 1, e, sum1, sum2 + nums[s], 1) ||
             recursiveImpl(nums, s, e - 1, sum1, sum2 + nums[e], 1));
    }

  private:
};
