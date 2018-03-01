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

class BasicCalculatorII {
  public:
    int calculate(string s)
    {
        stack<int> mystack;
        int i = 0, len = s.size();
        char op = ' ';
        while(i < len) {
            char c = s[i];
            if(c == ' ') {
                ++i;
                continue;
            }
            else if(!isdigit(c)) {
                ++i;
                op = c;
            }
            else {
                int start = i;
                while(i < len && isdigit(s[i]))
                    ++i;
                int t = stoi(s.substr(start, i - start));
                if(op == '+')
                    mystack.push(t);
                else if(op == '-')
                    mystack.push(-t);
                else if(op == '*') {
                    mystack.top() *= t;
                }
                else if(op == '/') {
                    mystack.top() /= t;
                }
                else {
                    mystack.push(t);
                }
            }
        }
        int res = 0;
        while(!mystack.empty()) {
            res += mystack.top();
            mystack.pop();
        }
        return res;
    }

  private:
};
