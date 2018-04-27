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

class DecodeWaysII {
  public:
    int numDecodings(string s)
    {
        if(s.empty() || s[0] == '0')
            return 0;
        long long divider = 1e9;
        unsigned long long first = 1, second = s[0] == '*' ? 9 : 1, cur = second;
        for(int i = 1; i < s.size(); ++i) {
            cur = 0;
            if(s[i] == '*') {
                cur += (second * 9);
                if(s[i - 1] == '1' || s[i - 1] == '*') {
                    cur += (first * 9);
                }
                if(s[i - 1] == '2' || s[i - 1] == '*') {
                    cur += (first * 6);
                }
            }
            else {
                // two char
                if(s[i - 1] == '1' || s[i - 1] == '*')
                    cur += first;
                if(s[i] <= '6' && (s[i - 1] == '2' || s[i - 1] == '*'))
                    cur += first;
                // one char
                if(s[i] != '0')
                    cur = second;
            }
            cur %= divider;
            first = second;
            second = cur;
        }
        return cur;
    }

  private:
};
