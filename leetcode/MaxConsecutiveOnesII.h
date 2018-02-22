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

class MaxConsecutiveOnesII {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int left = 0, cnt = 0, right = 0;
        // if we can flip k times
        int k = 1;
        // sliding window like implementation
        queue<int> q;
        while(right < nums.size()) {
            if(nums[right] == 0) {
                q.push_back(right);
            }
            if(q.size() > k) {
                left = q.front() + 1;
                q.pop();
            }
            cnt = max(cnt, right - left + 1);
            ++right;
        }
        return cnt;
    }

  private:
};
