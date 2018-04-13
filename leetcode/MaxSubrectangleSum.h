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

class MaxSubrectangleSum {
  public:
    int maxSubrec(vector<vector<int> >& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int maxSum = numeric_limits<int>::min();
        for(int left = 0; left < n; ++left) {
            vector<int> rowSum(m, 0);
            for(int right = left; right < n; ++right) {
                for(int i = 0; i < m; ++i) {
                    rowSum[i] += matrix[i][right];
                }
                maxSum = max(maxSum, maxSubarraySum(rowSum));
            }
        }
        return maxSum;
    }

  private:
    int maxSubarraySum(vector<int>& rowSum)
    {
        int curSum = 0, maxSum = numeric_limits<int>::min();
        for(int i = 0; i < rowSum.size(); ++i) {
            if(curSum > 0) {
                curSum += rowSum[i];
            }
            else {
                curSum = rowSum[i];
            }
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};
