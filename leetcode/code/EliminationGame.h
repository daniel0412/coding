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

class EliminationGame {
  public:
    int lastRemaining(int n) { return impl(n, false); }

  private:
    int impl(int n, bool reverse)
    {
        if(n == 1)
            return 1;
        if(reverse) {
            if(n % 2 == 0) {
                return 2 * impl(n / 2, !reverse) - 1;
            }
            else {
                return 2 * impl(n / 2, !reverse);
            }
        }
        else {
            return 2 * impl(n / 2, !reverse);
        }
    }
};
