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

class NumberOfLongestIncreasingSubseq {
  public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int cnt = 1;
        int numReplacements = 0;
        vector<int> res;
        for(auto n : nums) {
            auto iter = lower_bound(nums.begin(), nums.end(), n);
            if(iter == res.end()) {
                res.push_back(n);
                cnt += numReplacements;
                numReplacements = 0;
            }
            else if(iter == res.end() - 1) {
                ++cnt;
            }
            else {
                *iter = n;
                ++numReplacements;
            }
        }
        return cnt;
    }

  private:
};
