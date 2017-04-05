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
        if(nums.empty())
            return 0;
        return countImpl(nums, 0, nums.size() - 1);
    }

  private:
    int countImpl(vector<int>& nums, int start, int end)
    {
        int res = 0;
        if(start < end) {
            int mid = start + ((end - start) / 2);
            res = countImpl(nums, start, mid) + countImpl(nums, mid + 1, end) +
                mergeCount(nums, start, mid, end);
        }
        return res;
    }

    int mergeCount(vector<int>& nums, int start, int mid, int end)
    {
        int totalCount = 0;
        int leftId = start, rightId = mid + 1;

        while(leftId <= mid && rightId <= end) {
            long long numLong1 = nums[leftId], numLong2 = nums[rightId];
            if(numLong1 > 2 * numLong2) {
                totalCount += (mid - leftId + 1);
                ++rightId;
            }
            else {
                ++leftId;
            }
        }
        sort(nums.begin() + start, nums.begin() + end + 1);
        return totalCount;
    }
};
