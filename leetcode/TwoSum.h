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

class TwoSum {
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        if(nums.size() <= 2)
            return res;
        sort(nums.begin(), nums.end());
        for(int firstId = 0; firstId < nums.size() / 2; ++firstId) {
            int secondId = binarySearch(
                nums, firstId + 1, nums.size() - 1, target - nums[firstId]);
            if(secondId != -1) {
                res.push_back(firstId);
                res.push_back(secondId);
                break;
            }
        }
        return res;
    }

  private:
    // return the index, -1 if not found
    int binarySearch(const vector<int>& nums,
                     int start,
                     int end,
                     const int target)
    {
        while(start <= end) {
            int mid = start + (end - start) * 0.5;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }
};
