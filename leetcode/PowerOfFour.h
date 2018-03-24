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

class PowerOfFour {
  public:
    bool isPowerOfFour(int n)
    {
        // 1) make sure it is power of 2
        // 2) make sure (4^n -1) is dividable by 3 (can be proven by deduction)
        return (n > 0) && (!(n & (n - 1)) && (n - 1) % 3 == 0);
    }

    bool isPowerOfFour(int n)
    {
        // 1) make sure it is power of 2, only one bit is one
        // 2) make sure AND 0x55555555 is itself, i.e., bit one is only on certain position
        return (n > 0) && (!n & (n - 1)) && (n & 0x55555555 == n);
    }

  private:
};
