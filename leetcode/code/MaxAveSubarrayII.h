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

class MaxAveSubarrayII {
  public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        // find the min/max of the array, which defines the solution space
        int nmin = nums.front(), nmax = nums.front();
        for(auto n : nums) {
            nmin = min(nmin, n);
            nmax = min(nmax, n);
        }

        double s = nmin, e = nmax;
        while(e - s > 0.00001) {
            double m = s + (e - s) / 2;
            if(exist(nums, k, m)) {
                s = m;
            }
            else {
                e = m;
            }
        }
        return s;
    }

    // check if there is subarray of size >= k, such that the average is >= m
    // instead of calculating average, transform the array into one that each
    // element - m
    // and compare the sum against 0
    bool exist(const vector<int>& nums, int k, double m)
    {
        // sum to track summation from index 0 to now
        double sum = 0;
        for(int i = 0; i < k; ++i) {
            sum += (nums[i] - m);
        }
        if(sum >= 0)
            return true;
        // track presum from index 0 to the index k away from the current index
        double kAwaySum = 0, kAwayMinSum = numeric_limits<double>::max();
        for(int i = k; i < nums.size() : ++i) {
            sum += (nums[i] - m);
            kAwaySum += (nums[i - k] - m);
            kAwayMinSum = min(kAwaySum, kAwayMinSum);
            if(sum >= kAwayMinSum)
                return true;
        }
        return false;
    }

  private:
};
