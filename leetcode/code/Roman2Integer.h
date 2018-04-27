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

class Roman2Integer {
  public:
      int romanToInt(string s) {
          if(s.empty())
              return 0;
          unordered_map<char, int> m = {{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}};
          int res = m[s[0]];
          for(size_t i = 1; i < s.size(); ++i) {
              int prev = m[s[i-1]];
              int cur = m[s[i]];
              res += cur;
              if(cur > prev) res -= (2*prev);
          }
          return res;
      }

  private:
};
