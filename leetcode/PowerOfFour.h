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
        return (n > 0) && (!(n & (n - 1)) && (n - 1) % 3 == 0);
    }

  private:
};
