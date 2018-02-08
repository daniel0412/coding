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

class SubarraySumEqualsK {
  public:
    int subarraySum(vector<int>& nums, int k)
    {
        // make sure to initialize sum 0, count 1
        // to include sum from index 0 to the current index
        unordered_map<int, int> sumToCount{{0, 1}};
        int res = 0, sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += sumToCount[sum - k];
            ++sumToCount[sum];
        }
        return res;
    }

  private:
};
