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

class LongestIncreasingSubseq {
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> res;
        for(auto n : nums) {
            auto iter = lower_bound(res.begin(), res.end(), n);
            if(iter == res.end())
                res.push_back(n);
            else
                *iter = n;
        }
        return res.size();
    }


  private:
};
