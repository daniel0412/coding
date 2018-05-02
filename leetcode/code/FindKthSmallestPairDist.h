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

class FindKthSmallestPairDist {
  public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), less<int>());
        int low = numeric_limits<int>::max();
        int high = numeric_limits<int>::min();
        for(int i = 1; i < (int) nums.size(); ++i) {
            low = min(low, nums[i] - nums[i - 1]);
        }
        high = nums.back() - nums.front();
        // ATTENTION: cannot use normal binary search to return when count
        // equals, has to
        // gradually increase low, untill low == high to return low
        // because when count > k, does not mean the distance is not the k-th
        // smallest
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(countPairs(nums, mid) < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }

  private:
    // return number of pairs whose distance is no greater than val
    int countPairs(const vector<int>& nums, int dist)
    {
        int res = 0;
        for(int i = 0; i < (int) nums.size(); ++i) {
            res +=
                (distance(nums.begin() + i,
                          upper_bound(
                              nums.begin() + i, nums.end(), nums[i] + dist)) -
                 1); // minus 1 to get the count
        }
        return res;
    }
};
