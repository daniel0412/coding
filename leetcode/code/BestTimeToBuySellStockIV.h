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

class BestTimeToBuySellStockIV {
  public:
    int maxProfit(int k, vector<int>& prices)
    {
        if(prices.size() < 2)
            return 0;
        // trap: make sure process this situation separately
        if(k >= prices.size())
            return maxProfit2(prices);
        vector<int> global(k + 1, 0), local(k + 1, 0);
        for(int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            // rever order to preserve data from previous date
            for(int j = min(k, i); j >= 1; --j) {
                local[j] = max(local[j] + diff, global[j - 1] + max(0, diff));
                global[j] = max(global[j], local[j]);
            }
        }
        return global.back();
    }

  private:
    int maxProfit2(vector<int>& prices)
    {
        int maxP = 0;
        for(int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            maxP += (diff > 0 ? diff : 0);
        }
        return maxP;
    }
};
