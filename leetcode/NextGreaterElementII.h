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
            return nums;
        stack<int> s;
        vector<int> res(nums.size(), -1);
        int i = 0;
        int n = nums.size();
        while(i < 2 * n - 1) {
            int x = nums[i % n];
            while(!s.empty() && nums[s.top()] < x) {
                res[s.top()] = x;
                s.pop();
            }
            if(i < n) {
                s.push(i);
            }
            ++i;
        }
        return res;
    }

  private:
};
