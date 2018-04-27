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

class FindPeakElement {
  public:
    int findPeakElement(vector<int>& nums)
    {
        if(nums.empty())
            return -1;
        if(nums.size() == 1)
            return 0;
        int s = 0, e = nums.size() - 1, m = 0;
        while(s < e) {
            m = s + (e - s) / 2;
            if(nums[m] < nums[m + 1]) {
                s = m + 1;
            }
            else {
                e = m;
            }
        }
        return e;
    }
  private:
};
