/* 493. Reverse Pairs
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 *nums[i] > 2*nums[j].
 *
 * You need to return the number of important reverse pairs in the given array.
 *
 * Example1:
 *
 * Input: [1,3,2,3,1]
 * Output: 2
 * Example2:
 *
 * Input: [2,4,3,5,1]
 * Output: 3
 *
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
#include <queue>
#include <functional>
#include <utility>

using namespace std;

class ReversePair {
  public:
    int reversePairs(vector<int>& nums)
    {
        if(nums.size() < 2)
            return 0;
        return mergeCount(nums, 0, nums.size() - 1);
    }

  private:
    int mergeCount(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return 0;
        int mid = left + (right - left) / 2;
        int cnt = 0;
        cnt = mergeCount(nums, left, mid) + mergeCount(nums, mid + 1, right);

        for(int i = left, j = mid + 1; i <= mid; ++i) {
            // here use division to avoid int x 2 overflow
            while(j <= right && nums[i] / 2 > nums[j])
                ++j;
            cnt += (j - mid - 1);
        }
        // make sure the merged interval are sorted
        // sort(nums.begin() + left, nums.begin() + right + 1);
        // just merge since both left/right arrays are sorted already
        inplace_merge(nums.begin() + left,
                      nums.begin() + mid + 1,
                      nums.begin() + right + 1);
        return cnt;
    }
};
