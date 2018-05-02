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

class UglyNumberII {
  public:
    int nthUglyNumber(int n)
    {
        vector<int> res(1, 1);
        // keep track of next number that need to x2, x3, x5
        int i2 = 0, i3 = 0, i5 = 0;
        while(res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int m = min(m2, min(m3, m5));
            if(m == m2)
                ++i2;
            if(m == m3)
                ++i3;
            if(m == m5)
                ++i5;
            res.push_back(m);
        }
        return res.back();
    }

  private:
};
