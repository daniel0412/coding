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

class BeautifulArrangementsII {
  public:
      vector<int> constructArray(int n, int k) {
          // max distinct diff is n-1
          if(k > n-1) return {};
          vector<int> res;
          int i = 1, j = n;
          while(i < j) {
              if(k > 1) {
                  res.push_back(k--%2 ? i++ : j--);
              }else {
                  res.push_back(i++);
              }
          }
          return res;
      }
  private:
};
