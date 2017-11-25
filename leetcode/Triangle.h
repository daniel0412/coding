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

class Triangle {
  public:
    int minimumTotal(vector<vector<int> >& triangle)
    {
        if(triangle.empty())
            return 0;
        // bottom up dp
        vector<int> dp(triangle.back());
        int n = triangle.size();
        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp.front();
    }

  private:
};
