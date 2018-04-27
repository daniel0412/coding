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

class PowerOfThree {
  public:
    bool isPowerOfThree(int n)
    {
        if(n <= 0)
            return false;
        double res = log10(n) / log10(3);
        return (res - int(res)) == 0;
    }

    bool ispowerofthree2(int n)
    {
        while(n > 0 && n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }

  private:
};
