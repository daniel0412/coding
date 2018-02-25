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

class DecodeString {
  public:
      string decodeString(string s) {
          int i = 0, start = 0, len = s.size();
          string res;
          stack<string> ss;
          while(i < len) {
              start = i;
              while(i < len && isdigit(s[i])) ++i;
              if(i > start) {
                  ss.push(s.substr(start, i - start));
                  while(!s.empty()) {
                      if(s[i] == '[') {
                          ++i;
                      }
                      start = i;
                      while(i < len && isdigit(s[i])) ++i;
                      // next is a number
                      if(i > start) {
                          ss.push(s.bustr(start, i - start));
                      }else {
                          while(i < len && isalpha(s[i])) ++i;
                          string midres;
                          string tmp = s.substr(start, i - start);
                          if(s[i] == ']') {
                              int num = atoi(ss.top().c_str());
                              ss.pop();
                              for(int k = 0; k < num; ++k) {
                                  midres += tmp;
                              }
                          }
                          while(isalpha(ss.top()[0])) {
                              midres = ss.top() + midres;
                              ss.pop();
                          }
                          ss.push(midres);
                      }
                  }
                  res += ss.top();
                  ss.pop();
              }else {
                  while(i < len && isalpha(s[i])) ++i;
                  res += s.substr(start, i - start);
              }
          }
      }
  private:
};
