/* 327. Count of Range Sum
 *
 * Given an integer array nums, return the number of range sums that lie in
 *[lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 *indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 *
 * Example:
 * Given nums = [-2, 5, -1], lower = -2, upper = 2,
 * Return 3.
 * The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are:
 *-2, -1, 2.
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
#include <utility>

using namespace std;

class CountOfRangeSum {
  public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        multiset<long long> sums;
        int count = 0;
        long long curSum = 0;
        // this is important to include single element range
        sums.insert(0);

        for(int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            count += distance(sums.lower_bound(curSum - upper),
                              sums.upper_bound(curSum - lower));
            sums.insert(curSum);
        }
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        vector<long long> sums(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return mergeCount(sums, lower, upper, 0, sums.size() - 1);
    }

    int mergeCount(vector<int>& sums,
                   const int lower,
                   const int upper,
                   int left,
                   int right)
    {
        if(right == left)
            return 0;
        int cnt = 0, mid = left + (right - left) / 2;
        for(int i = left; i <= mid; ++i) {
            int j = mid + 1, k = mid + 1;
            while(j <= right && sums[j] - sums[i] <= upper)
                ++j;
            while(k <= right && sums[k] - sums[i] < lower)
                ++k;
            cnt += (j - k);
        }
        inplace_merge(sums.begin() + left,
                      sums.begin() + mid + 1,
                      sums.begin() + right + 1);
        return cnt;
    }

  private:
};
