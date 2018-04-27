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

class MaxAvgSubarray {
  public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        if(nums.size() < k)
            return 0;
        long long sum = accumulate(nums.begin(), nums.begin() + k, 0);
        long long maxSum = sum;
        for(int i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum * 1.0 / k;
    }

  private:
};
