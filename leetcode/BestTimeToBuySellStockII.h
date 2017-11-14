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

class BestTimeToBuySellStockII {
  public:
    int maxProfit(vector<int>& prices)
    {
        int maxP = 0;
        if(prices.size() > 1) {
            for(int i = 1; i < prices.size(); ++i) {
                int diff = prices[i] - prices[i - 1];
                if(diff > 0)
                    maxP += diff;
            }
        }
        return maxP;
    }

  private:
};
