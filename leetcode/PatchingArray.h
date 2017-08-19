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
        long long res = 0, curSum = 1;
        int i = 0;
        while(curSum <= n) {
            if(i < nums.size() && nums[i] <= curSum) {
                curSum += nums[i++];
            }
            else {
                curSum = curSum << 1;
                ++res;
            }
        }
        return res;
    }

  private:
};
