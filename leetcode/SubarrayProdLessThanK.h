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

class SubarrayProdLessThanK {
  public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(k <= 1)
            return 0;
        int left = 0, prod = 1, res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while(prod >= k)
                prod /= nums[left++];
            res += (i - left + 1);
        }
        return res;
    }

  private:
};
