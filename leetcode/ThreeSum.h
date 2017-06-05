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

class ThreeSum {
  public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > res;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for(int a = 0; a < nums.size() - 2; ++a) {
            // if the first number value already considered, skip
            if(a > 0 && nums[a] == nums[a - 1])
                continue;
            int b = a + 1, c = nums.size() - 1;
            while(b < c) {
                // if the second number value already considered, skip
                if(b > a + 1 && nums[b] == nums[b - 1]) {
                    ++b;
                    continue;
                }
                int sum = nums[a] + nums[b] + nums[c];
                if(sum == 0) {
                    res.push_back(vector<int>({nums[a], nums[b], nums[c]}));
                    ++b;
                    --c;
                }
                else if(sum < 0) {
                    ++b;
                }
                else {
                    --c;
                }
            }
        }
        return res;
    }

  private:
};
