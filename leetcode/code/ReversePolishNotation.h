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

class ReversePolishNotation {
  public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        for(const auto& a : tokens) {
            if(a == "+" || a == "-" || a == "*" || a == "/") {
                if(s.size() < 2)
                    break;
                int t = s.top();
                s.pop();
                int k = s.top();
                s.pop();
                if(a == "+")
                    k += t;
                else if(a == "-")
                    k -= t;
                else if(a == "*")
                    k *= t;
                else if(a == "/")
                    k /= t;
                s.push(k);
            }
            else {
                s.push(stoi(a));
            }
        }
        return s.empty() ? 0 : s.top();
    }

  private:
};
