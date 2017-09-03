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

class NumOfBoomerangs {
  public:
    int numberOfBoomerangs(vector<pair<int, int> >& points)
    {
        int res = 0;
        for(int i = 0; i < points.size(); ++i) {
            unordered_map<long long, int> m;
            for(int j = 0; j < points.size(); ++j) {
                if(i != j) {
                    ++m[dist(points[i], points[j])];
                }
            }
            for(auto& kv : m) {
                if(kv.second >= 2) {
                    res += (kv.second * (kv.second - 1));
                }
            }
        }
        return res;
    }

  private:
    long long dist(const pair<int, int>& a, const pair<int, int>& b)
    {
        long long adiff = a.first - b.first;
        long long bdiff = a.second - b.second;
        return adiff * adiff + bdiff * bdiff;
    }
};
