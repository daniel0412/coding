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

class PaintHouseII {
  public:
      int minCostII(vector<vector<int>>& costs) {
          if(costs.empty() || costs[0].empty()) return 0;
          int minc1 = 0, minc2 = 0, mini1 = -1;
          for(size_t i = 0; i < costs.size(); ++i) {
              int tmp_minc1 = INT_MAX, tmp_minc2 = INT_MAX, tmp_mini1 = -1;
              for(size_t j = 0; j < costs[i].size(); ++j) {
                  int tmpcost =  costs[i][j] + (j == mini1 ? minc2 : minc1);
                  if(tmpcost < tmp_minc1) {
                      tmp_minc2 = tmp_minc1;
                      tmp_minc1 = tmpcost;
                      tmp_mini1 = j;
                  }else if(tmpcost < tmp_minc2) {
                      tmp_minc2 = tmpcost;
                  }
              }
              minc1 = tmp_minc1; mini1 = tmp_mini1;
              minc2 = tmp_minc2;
          }
          return minc1;
      }
  private:
};
