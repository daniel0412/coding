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

class BestTimeToBuySellStock {
  public:
    int maxProfit(vector<int>& prices)
    {
        int profits = 0;
        int minP = numeric_limits<int>::max();
        for(auto p : prices) {
            if(p < minP) {
                minP = p;
            }
            else {
                profits = max(profits, p - minP);
            }
        }
        return profits;
    }

  private:
};
