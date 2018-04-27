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

class PatchingArray {
  public:
    int minPatches(vector<int>& nums, int n)
    {
        long long miss = 1;
        int res = 0, i = 0;
        while(miss <= n) {
            if(i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            }
            else {
                miss = curSum << 1;
                ++res;
            }
        }
        return res;
    }

  private:
};
