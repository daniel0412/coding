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

class MaxSquare {
  public:
    int maximalSquare(vector<vector<char> >& matrix)
    {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        int sides = 0;
        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == '1') {
                dp[i] = 1;
                sides = 1;
            }
        }

        for(int i = 1; i < m; ++i) {
            int prev = 0;
            if(matrix[i][0] == '1') {
                prev = 1;
                sides = max(sides, prev);
            }
            for(int j = 1; j < n; ++j) {
                int tmpSide = INT_MAX;
                if(matrix[i][j] == '0') {
                    tmpSide = 0;
                }
                else {
                    tmpSide = min(dp[j - 1], dp[j]);
                    tmpSide = min(tmpSide, prev) + 1;
                    sides = max(sides, tmpSide);
                }
                dp[j - 1] = prev;
                prev = tmpSide;
            }
            dp[n - 1] = prev;
        }
        return sides * sides;
    }

  private:
};
