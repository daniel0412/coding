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

class MinSizeSubarraySum {
  public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        // two pointer
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0, minlen = n + 1;
        while(right < n) {
            sum += nums[right++];
            if(sum >= s) {
                while(sum >= s) {
                    sum -= nums[left++];
                }
                minlen = min(minlen, right - left + 1);
            }
        }
        return minlen == n + 1 ? 0 : minlen;
    }

  private:
};
