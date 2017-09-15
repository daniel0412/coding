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

class Heaters {
  public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        int minR = INT_MIN;
        if(heaters.empty() || houses.empty())
            return minR;
        sort(heaters.begin(), heaters.end());
        for(auto h : houses) {
            // find upper bound
            int l = 0, r = heaters.size() - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(heaters[l] <= h)
                    l = mid + 1;
                else {
                    r = mid - 1;
                }
            }
            int tmpR = INT_MAX;
            if(l == 0) {
                tmpR = abs(h - heaters[0]);
            }
            else if(l == heaters.size()) {
                tmpR = abs(h - heaters[l - 1]);
            }
            else {
                tmpR = min(abs(h - heaters[l]), abs(h - heaters[l - 1]));
            }
            minR = max(minR, tmpR);
        }
        return minR;
    }

  private:
};
