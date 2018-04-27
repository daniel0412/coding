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

class SplitArrayWithEqualSum {
  public:
    // fix j, then split into left/right split problem
    // then O(n^2) rather than brute force O(n^3)
    bool splitArray(vector<int>& nums)
    {
        if(nums.size() < 7)
            return false;
        int n = nums.size();
        vector<int> sums = nums;
        for(int i = 1; i < (int) nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        // first locate j
        for(int j = 3; j < n - 3; ++j) {
            unordered_set<int> s;
            // local i to split [0-j]
            for(int i = 1; i < j - 1; ++i) {
                if(sums[i - 1] == (sums[j - 1] - sums[i])) {
                    s.insert(sums[i - 1]);
                }
            }
            // local k to split [j+1, n-1]
            for(int k = j + 2; k < n - 1; ++k) {
                int s3 = sums[k - 1] - sums[j];
                if(s3 == sums[n - 1] - sums[k] && s.count(s3)) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
};
