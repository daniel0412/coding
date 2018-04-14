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

class NextGreaterElementII {
  public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        if(nums.empty())
            return {};
        stack<int> s;
        vector<int> res(nums.size(), -1);
        size_t n = nums.size();
        // since nums may include duplicates
        // so stack is used to store index only, not the number value
        //  2n-1 since no need to check for the last element
        for(size_t i = 0; i < 2 * n - 1; ++i) {
            int id = i % n;
            while(!s.empty() && nums[s.top()] < nums[id]) {
                res[s.top()] = nums[id];
                s.pop();
            }
            // only need to find next greater element for the first n in cyclar
            // array
            if(i < n) {
                s.push(i);
            }
        }
        return res;
    }

  private:
};
