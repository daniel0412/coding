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

class BasicCalculator {
  public:
    int calculate(string s)
    {
        stack<int> st;
        int res = 0;
        size_t slen = s.size(), i = 0;
        int sign = 1;
        while(i < slen) {
            char c = s[i];

            if(isdigit(c)) {
                int num = 0;
                while(i < slen && isdigit(s[i])) {
                    num *= 10;
                    num += (s[i] - '0');
                    ++i;
                }
                res += (sign * num);
                --i;
            }
            else if(c == '+') {
                sign = 1;
            }
            else if(c == '-') {
                sign = -1;
            }
            else if(c == '(') {
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            }
            else if(c == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
            // include the case that when whitespace, just skip
            ++i;
        }
        return res;
    }

  private:
};
