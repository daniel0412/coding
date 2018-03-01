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
    int dfs(const string& s, int& i)
    {
        int sign = 1;
        int res = 0;
        while(i < s.size()) {
            if(s[i] == ' ') {
                ++i;
                continue;
            }
            else if(s[i] == '(') {
                res += (sign * dfs(s, ++i));
            }
            else if(s[i] == ')') {
                ++i;
                return res;
            }
            else if(isdigit(s[i])) {
                int tt = i;
                while(i < s.size() && isdigit(s[i]))
                    ++i;
                res += (sign * stoi(s.substr(tt, i - tt)));
            }
            else {
                sign = s[i++] == '+' ? 1 : -1;
            }
        }
        return res;
    }

  private:
};
