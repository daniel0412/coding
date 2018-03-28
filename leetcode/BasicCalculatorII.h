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
        int i = 0, sign = 1;
        char op = '+';
        while(i < s.size()) {
            if(s[i] == ' ') {
                ++i;
                continue;
            }
            else if(isdigit(s[i])) {
                int start = i;
                while(isdigit(s[i]))
                    ++i;
                int val = sign * stoi(s.substr(start, i - start));
                if(op == '*') {
                    val = mystack.top() * val;
                    mystack.pop();
                }
                else if(op == '/') {
                    val = mystack.top() / val;
                    mystack.pop();
                }
                mystack.push(val);
            }
            else {
                op = s[i];
                sign = s[i++] == '-' ? -1 : 1;
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
