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

class ShortestUnsortedContinuousSubarray {
  public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1)
            return 0;
        int start = -1, end = -2;  // in case start/end is not changed, meaning
                                   // 0 disordered elements
        int imax = nums[0], imin = nums[n - 1];
        for(int i = 1; i < n; ++i) {
            imax = max(imax, nums[i]);          // tracks max from 0 -> n-1
            imin = min(imin, nums[n - i - 1]);  // tracks min from n-1 -> 0
            if(imax > nums[i])
                end = i;
            if(imin < nums[n - i - 1])
                start = n - i - 1;
        }
        return end - start + 1;
    }

  private:
};
