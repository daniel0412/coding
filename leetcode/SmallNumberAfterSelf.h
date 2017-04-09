/* 315. Count of Smaller Numbers After Self
 *
 * You are given an integer array nums and you have to return a new counts
 *array. The counts array has the property where counts[i] is the number of
 *smaller elements to the right of nums[i].
 *
 * Example:
 *
 * Given nums = [5, 2, 6, 1]
 *
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * Return the array [2, 1, 1, 0].
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

class SmallNumberAfterSelf {
  public:
    vector<int> countSmall(vector<int>& nums)
    {
        vector<int> d_count(nums.size(), 0);
        vector<int> d_ordered;
        if(nums.size() <= 1)
            return d_count;
        for(int i = nums.size() - 1; i >= 0; --i) {
            int val = nums[i];
            int start = 0, end = d_ordered.size(), mid = 0;
            while(start < end) {
                mid = start + (end - start) / 2;
                if(val > d_ordered[mid]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            d_count[i] = end;
            d_ordered.insert(d_ordered.begin() + end, val);
        }
        return d_count;
    }

  private:
};
