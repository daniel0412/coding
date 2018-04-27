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

class Integer2Roman {
  public:
      string intToRoman(int num) {
          string res = "";
          if(num <= 0)
              return res;
          // this dict list all the places where 'minus' needed
          vector<pair<int, string> > dict{{1, "I"},
                                          {4, "IV"},
                                          {5, "V"},
                                          {9, "IX"},
                                          {10, "X"},
                                          {40, "XL"},
                                          {50, "L"},
                                          {90, "XC"},
                                          {100, "C"},
                                          {400, "CD"},
                                          {500, "D"},
                                          {900, "CM"},
                                          {1000, "M"}};
          for(auto p = dict.crbegin(); p != dict.crend(); ++p) {
              while(num >= p->first) {
                  res += p->second;
                  num -= p->first;
              }
          }
          return res;
      };
} private:
}
;
