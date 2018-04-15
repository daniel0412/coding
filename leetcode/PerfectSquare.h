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

class PerfectSquare {
  public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = sqrt(i); j >= 1; --j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
                if(dp[i] <= 2)
                    break;
            }
        }
        return dp.back();
    }

  private:
};
