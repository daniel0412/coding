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

class ThreeSumSmaller {
  public:
    int threeSumSmaller(vector<int>& nums, int target)
    {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int a = 0; a < nums.size() - 2; ++a) {
            int b = a + 1, c = nums.size() - 1;
            while(b < c) {
                if(nums[a] + nums[b] + nums[c] >= target) {
                    --c;
                }
                else {
                    count += (c - b);
                    ++b;
                }
            }
        }
        return count;
    }

  private:
};
