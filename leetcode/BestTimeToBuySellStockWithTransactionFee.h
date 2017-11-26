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

class BestTimeToBuySellStockWithTransactionFee {
  public:
    int maxProfit(vector<int>& prices, int fee)
    {
        if(prices.size() < 2)
            return 0;
        int sold = 0, hold = -prices[0];
        for(int i = 0; i < prices.size(); ++i) {
            int t = sold;
            sold = max(sold, hold + prices[i] - fee);
            hold = max(hold, t - prices[i]);
        }
        return sold;
    }

  private:
};
