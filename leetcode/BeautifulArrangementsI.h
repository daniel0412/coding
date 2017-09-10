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

class BeautifulArrangementsI {
  public:
    int countArrangement(int N)
    {
        if(N == 1)
            return 1;
        vector<int> nums(N + 1);
        for(int i = 0; i <= N; ++i) {
            nums[i] = i;
        }
        return helper(1, nums);
    }

  private:
    int helper(int start, vector<int>& nums)
    {
        if(start >= nums.size())
            return 1;
        int res = 0;
        for(int i = start; i < nums.size(); ++i) {
            if(start % nums[i] == 0 || nums[i] % start == 0) {
                swap(nums[start], nums[i]);
                res += helper(start + 1, nums);
                swap(nums[start], nums[i]);
            }
        }
        return res;
    }
};
