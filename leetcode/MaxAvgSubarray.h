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
        long long sum = 0;
        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        long long maxSum = sum;
        for(int i = k; i < nums.size(); ++i) {
            sum += nums[i];
            sum -= nums[i-k];
            maxSum = max(maxSum, sum);
        }
        return maxSum * 1.0 / k;
    }

  private:
};
