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

class DecodeWays {
  public:
    int numDecodings(string s)
    {
        // corner case
        if(s.empty() || s[0] == '0')
            return 0;
        // return recursiveImpl(s, 0);
        return dpImpl(s);
    }

  private:
    // recursive solution runs too long
    int recursiveImpl(const string& s, int start)
    {
        // when one decoding found, return 1
        if(start >= s.size())
            return 1;
        if(s[start] == '0')
            return 0;
        int res = 0;
        res += recursiveImpl(s, start + 1);
        if(start + 1 < s.size()) {
            if(s[start] == '1' || (s[start] == '2' && s[start + 1] <= '6')) {
                res += recursiveImpl(s, start + 2);
            }
        }
        return res;
    }

    int dpImpl(const string& s)
    {
        if(s.size() < 1 || s[0] == '0')
            return 0;
        int first = 1, second = 1, cur = second;
        for(int i = 1; i < s.size(); ++i) {
            cur = 0;
            // decode with preceding char as one number
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                cur += first;
            // decode current digit as single number
            if(s[i] != '0')
                cur += second;
            first = second;
            second = cur;
        }
        return cur;
    }
};
