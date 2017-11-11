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

class RemoveInvalidParenthesesII {
  public:
    string removeImpl1(string& s)
    {
        int cnt = 0;
        string tmp, res;
        // left->right, remove right invalid
        for(auto c : s) {
            if(c == ')' && cnt == 0) {
                continue;
            }
            tmp.append(c);
            if(c == '(')
                ++cnt;
            else if(c == ')')
                --cnt;
        }
        // right->left, remove left invalid
        cnt = 0;
        int i = tmp.size();
        while(--i >= 0) {
            if(tmp[i] == '(' && cnt == 0) {
                continue;
            }
            res.append(tmp[i]);
            if(tmp[i] == ')')
                ++cnt;
            else if(tmp[i] == '(')
                --cnt;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string removeImpl2(const string& s)
    {
        string res;
        int cnt;
        for(auto c : s) {
            if(c == '(') {
                ++cnt;
            }
            else if(c == ')') {
                if(cnt > 0) {
                    --cnt;
                    res = "(" + res + ")";
                }
            }
            else {
                res.append(c);
            }
        }
        return res;
    }

  private:
};
