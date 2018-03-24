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

class PowerOfTwo {
  public:
      // 1) make sure it is positive
      // 2) bit manipulation
    bool isPowerOfTwo(int n) { return (n > 0) && !(n & (n - 1)); }

    bool ispoweroftwo2(int n)
    {
        int cnt = 0;
        while(n > 0) {
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt == 1;
    }

  private:
};
