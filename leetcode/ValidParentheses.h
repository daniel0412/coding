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

class ValidParentheses {
  public:
      bool isValid(string s) {
          if(s.size() % 2 != 0) return false;
          stack<char> mystack;
          for(auto c : s) {
              if(c == '(' || c == '[' || c == '{') {
                  mystack.push(c);
              }else{
                  if(mystack.empty()) return false;
                  switch(c) {
                      case ')':
                          if(mystack.top() == '(') mystack.pop();
                          else return false;
                          break;
                      case ']':
                          if(mystack.top() == '[') mystack.pop();
                          else return false;
                          break;
                      case '}':
                          if(mystack.top() == '{') mystack.pop();
                          else return false;
                          break;
                      default:
                          return false;
                  }
              }
          }
          return mystack.empty();
      }
  private:
};
