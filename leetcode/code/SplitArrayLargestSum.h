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

class SplitArrayLargestSum {
  public:
    int splitArray(vector<int>& nums, int m)
    {
        return binarySearchImpl(nums, m);
    }

  private:
    int binarySearchImpl(const vector<int>& nums, int m)
    {
        // find the range of the split array sum
        int minSum = 0, maxSum = 0;
        for(const auto n : nums) {
            maxSum += n;
            minSum = max(minSum, n);
        }

        // binary search to find the min-max subarray sum
        int res = INT_MAX;
        while(minSum <= maxSum) {
            int midSum = minSum + (maxSum - minSum) / 2;
            //cout << "[" << minSum << ", " << maxSum << "]" << endl;
            //cout << "trying " << midSum;
            if(validSplitBelowSum(nums, m, midSum)) {
                res = min(res, midSum);
                maxSum = midSum - 1;
                //cout << " got " << res << endl;
            }
            else {
                minSum = midSum + 1;
                //cout << " but failed" << endl;
            }
        }
        return res;
    }

    bool validSplitBelowSum(const vector<int>& nums, int m, int givenSum)
    {
        int n = nums.size();
        int splitSum = 0;
        for(int i = 0; i < n; ++i) {
            splitSum += nums[i];
            if(splitSum <= givenSum) {
                continue;
            }
            else {
                splitSum = nums[i];
                --m;
                if(n - i <= m)
                    return true;
                if(m <= 0)
                    return false;
            }
        }
        return true;
    }
};
