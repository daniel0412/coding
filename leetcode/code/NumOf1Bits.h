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

class NumOf1Bits {
  public:
    int countOnes(int n)
    {
        int cnt = 0;
        while(n != 0) {
            n = n & (n - 1);
            ++cnt;
        }

        return cnt;
    }

  private:
};
