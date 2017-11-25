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

class BestTimeToBuySellStockIII {
  public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() < 2)
            return 0;
        vector<int> global(3, 0), local(3, 0);
        for(int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for(int j = 2; j >= 1; --j) {
                local[j] = max(local[j] + diff, global[j - 1] + max(0, diff));
                global[j] = max(global[j], local[j]);
            }
        }
        return global.back();
    }

  private:
};
