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

class RangeModule {
  public:
    RangeModule() {}

    void addRange(int left, int right)
    {
        if(left >= right)
            return;

        if(d_map.empty()) {
            d_map[left] = right;
            return;
        }

        auto liter = d_map.upper_bound(left);
        auto riter = d_map.upper_bound(right);

        if(liter != d_map.begin()) {
            liter = prev(liter);
            if(liter->second < left)
                liter = next(liter);
        }
        if(liter == d_map.end()) {
            d_map[left] = right;
            return;
        }

        left = min(liter->first, left);

        if(liter != riter) {
            riter = prev(riter);
            right = max(riter->second, right);
            riter = next(riter);
        }

        d_map.erase(liter, riter);
        d_map[left] = right;
    }

    bool queryRange(int left, int right)
    {
        auto liter = d_map.upper_bound(left);
        if(liter == d_map.begin() || prev(liter)->second < right)
            return false;
        return true;
    }

    void removeRange(int left, int right)
    {
        if(left >= right || d_map.empty())
            return;

        auto liter = d_map.lower_bound(left);
        if(liter != d_map.begin()) {
            liter = prev(liter);
            if(liter->second <= left)
                liter = next(liter);
        }

        if(liter == d_map.end()) return;

        int left1 = 0, right1 = 0;
        if(left > liter->first) {
            left1 = liter->first;
            right1 = left;
        }

        int left2 = 0, right2 = 0;
        auto riter = d_map.lower_bound(right);
        if(liter != riter) {
            riter = prev(riter);
            if(right < riter->second) {
                left2 = right;
                right2 = riter->second;
            }
            riter = next(riter);
        }

        d_map.erase(liter, riter);
        if(left1 != right1)
            d_map[left1] = right1;
        if(left2 != right2)
            d_map[left2] = right2;
    }

  private:
    map<int, int> d_map;
};
