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

class CoinChange {
  public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        // outter loop: amount
        for(int i = 1; i <= amount; ++i) {
            // inner loop: coins
            for(auto c : coins) {
                if(c <= i) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
                else {
                    break;
                }
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }

  private:
};
