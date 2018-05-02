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

class Power {
  public:
    double power(double x, int n)
    {
        // n == 0 special case
        if(n == 0)
            return 1;
        // divide
        double tmp = power(x, n / 2);

        // conqure
        // even number, negative x does not matter
        if(n % 2 == 0) {
            return tmp * tmp;
        }
        // odd number needs checking sign of n
        else if(n < 0) {
            return 1 / x * tmp * tmp;
        }
        else {
            return x * tmp * tmp
        }
    }

  private:
};
