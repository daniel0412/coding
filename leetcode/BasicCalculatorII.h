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
        int res = 0, sign = 1;
        stack<int> st;
        int i = 0, slen = s.size();
        while(i < slen) {
            char c = s[i];
            if(c == '+') {
                sign = 1;
            }
            else if(c == '-') {
                sign = -1;
            }
            else if(c == '/') {
                sign = 2;
            }
            else if(c == '*') {
                sign = 3;
            }
            else if(isdigit(c)) {
                int num = 0;
                while(i < slen && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                --i;
                if(sign == 1 || sign == -1) {
                    st.push(sign * num);
                }
                else {
                    int tmp = 0;
                    if(sign == 2) {
                        tmp = st.top() * num;
                    }
                    else {
                        tmp = st.top() / num;
                    }
                    s.pop();
                    s.push(tmp);
                }
            }
            ++i;
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }

  private:
};
