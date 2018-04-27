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

class MaxProdOfThreeNum {
  public:
    int maximumProduct(vector<int>& nums)
    {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums.back(),
                   nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }

    int maximumProduct(vector<int>& nums)
    {
        if(nums.size() < 3)
            return 0;
        int mx1 = numeric_limits<int>::min(), mx2 = mx1, mx3 = mx1,
            m1 = numeric_limits<int>::max(), m2 = m1;

        for(auto n : nums) {
            if(n > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = n;
            }
            else if(n > mx2) {
                mx3 = mx2;
                mx2 = n;
            }
            else if(n > mx3) {
                mx3 = n;
            }
            if(n < m1) {
                m2 = m1;
                m1 = n;
            }
            else if(n < m2) {
                m2 = n;
            }
        }
        return max(mx1 * mx2 * mx3, mx1 * m1 * m2);
    }

  private:
};
