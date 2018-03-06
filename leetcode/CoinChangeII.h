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

class CoinChangeII {
  public:
    int change(int amount, vector<int>& coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // outter: coins
        for(auto c : coins) {
            // inner: amount
            for(int i = c; i <= amount; ++i) {
                dp[i] += dp[i - c];
            }
        }
        return dp.back();
    }

  private:
};
