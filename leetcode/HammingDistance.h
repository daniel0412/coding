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

class HammingDistance {
  public:
    int hammingDistance(int x, int y) {

        int res = 0;
        int c = x ^ y;
        int i = 32;
        while(i-- > 0) {
            res += c & 1;
            c = c >> 1;
        }
        return res;
    }

  private:
};
