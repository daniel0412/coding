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

class MaxSumOfRectangleNoGreaterThanK {
  public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k)
    {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int maxs = numeric_limits<int>::min();
        // brute force for all possible rectangles
        // fix left col, try all right cols
        // move left col, try all right cols
        for(int left = 0; left < n; ++left) {
            // col vector, which ith element accumulate sum along the i-th row
            vector<int> rowSums(m, 0);
            for(int right = left; right < n; ++right) {
                // accumulate sum
                for(int i = 0; i < m; ++i) {
                    rowSums[i] += matrix[i][right];
                }
                set<int> s;
                // in case psum = k, needs 0 to insert this records
                s.insert(0);
                int psum = 0;
                for(auto nn : rowSums) {
                    psum += nn;
                    // psum-x <= k is required => psum-k <= x
                    auto iter = s.lower_bound(psum - k);
                    if(iter != s.end()) {
                        maxs = max(maxs, psum - *iter);
                    }
                    // insert presum, used for later range sum
                    s.insert(psum);
                }
            }
        }
        return maxs;
    }

  private:
};
