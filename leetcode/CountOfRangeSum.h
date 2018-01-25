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

  private:
};
