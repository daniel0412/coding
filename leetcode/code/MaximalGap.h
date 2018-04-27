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

class MaximalGap {
  public:
    int maximumGap(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 2)
            return 0;
        int mx = numeric_limits<int>::min(), mn = numeric_limits<int>::max();
        for(auto n : nums) {
            mx = max(mx, n);
            mn = min(mn, n);
        }

        // do this since minGap cannot be ZERO as a dividor
        int minGap = (mx - mn) / len + 1;
        int numBuckets = (mx - mn) / minGap + 1;

        vector<int> minvec(numBuckets, numeric_limits<int>::max());
        vector<int> maxvec(numBuckets, numeric_limits<int>::min());
        unordered_set<int> s;

        for(auto n : nums) {
            int id = (n - mn) / minGap;
            minvec[id] = min(minvec[id], n);
            maxvec[id] = max(maxvec[id], n);
            s.insert(id);
        }
        int maxGap = 0, preId = 0;
        for(int i = 1; i < numBuckets; ++i) {
            if(s.count(i) == 0)
                continue;
            maxGap = max(maxGap, minvec[i] - maxvec[preId]);
            preId = i;
        }
        return maxGap;
    }

  private:
};
