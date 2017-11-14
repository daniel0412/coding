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

class BestTimeToBuySellStockWithCooldown {
  public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() <= 1)
            return 0;
        int preSell = 0, curSell = 0;
        int preBuy = -prices[0], curBuy = 0;
        for(int i = 1; i < prices.size(); ++i) {
            curSell = max(preSell, preBuy + prices[i]);
            curBuy = max(preBuy, preSel - prices[i]);
            preSell = curSell;
            preBuy = curBuy;
        }
        return curSell;
    }

  private:
};
