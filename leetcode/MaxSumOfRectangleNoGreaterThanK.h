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
        int m = matrix.size(), n = matrix[0].size();
        int maxSum = numeric_limits<int>::min();

        // loop over the stating col
        for(int i = 0; i < n; ++i) {
            vector<int> sum(m, 0);
            // left->right sum
            for(int j = i; j < n; ++j) {
                // for up->down sum
                for(int l = 0; l < m; ++l) {
                    sum[l] += matrix[l][j];
                }
                set<int> s;
                s.insert(0);
                int curSum = 0;
                for(const auto nn : sum) {
                    curSum += nn;
                    auto iter = s.lower_bound(curSum - k);
                    if(iter != s.end())
                        maxSum = max(maxSum, curSum - *iter);
                    s.insert(curSum);
                }
            }
        }
        return maxSum;
    }

  private:
};
