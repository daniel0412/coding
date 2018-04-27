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

class WeightedRandomNumber {
  public:
      WeightedRandomNumber(vector<pair<int,int>>& v) {
          for(const auto& p : v) {
              d_m[v.first] = v.second;
              d_sum += v.second;
          }
      }

      int getRandom() {
          int id = rand() % d_sum;
          long long cur_sum = 0;
          auto iter = d_m.begin();
          for(; iter != d_m.end(); ++iter) {
              cur_sum += iter->second;
              if(cur_sum > id) break;
          }
          return iter->first;

      }

      void setWeight(int key, int weight) {
          d_m[key] = weight;
      }
  private:
      long long d_sum;
      unordered_map<int, int> d_m;
};
