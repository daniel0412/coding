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

class BasicCalculatorIII {
  public:
    int calculate(string s)
    {
        int start = 0;
        return dfs(s, start);
    }

    int dfs(const string& s, int& i)
    {
        stack<int> mystack;
        char op = ' ';
        while(i < s.size()) {
            if(s[i] == ' ') {
                ++i;
                continue;
            }
            else if(s[i] == '(') {
                int res = dfs(s, ++i);
                calculate(mystack, op, res);
            }
            else if(s[i] == ')') {
                ++i;
                return sumOfStack(mystack);
            }
            else if(isdigit(s[i])) {
                int start = i;
                while(i < s.size() && isdigit(s[i]))
                    ++i;
                int num = stoi(s.substr(start, i - start));
                calculate(mystack, op, num);
            }
            else {
                op = s[i++];
            }
        }
        return sumOfStack(mystack);
    }

    int sumOfStack(stack<int>& mystack)
    {
        int res = 0;
        while(!mystack.empty()) {
            res += mystack.top();
            mystack.pop();
        }
        return res;
    }

    void calculate(stack<int>& mystack, const char op, int num)
    {
        switch(op) {
            case '+':
                mystack.push(num);
                break;
            case '-':
                mystack.push(-1 * num);
                break;
            case '*':
                mystack.top() *= num;
                break;
            case '/':
                mystack.top() /= num;
                break;
            default: // first empty op
                mystack.push(num);
                break;
        }
    }

  private:
};
