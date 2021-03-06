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

class AddBinary {
  public:
    // a little bit faster
    string addBinary(string a, string b)
    {
        if(a.empty() || b.empty()) {
            return a.empty() ? b : a;
        }
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0, sum = 0;
        string res;
        while(i >= 0 && j >= 0) {
            sum = a[i--] + b[j--] + carry - 2 * '0';
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        while(i >= 0) {
            sum = a[i--] + carry - '0';
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        while(j >= 0) {
            sum = b[j--] + carry - '0';
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        if(carry > 0)
            res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }

    // more concise coding
    string addBinary(string a, string b)
    {
        if(a.empty())
            return b;
        if(b.empty())
            return a;
        int an = a.size(), bn = b.size();
        int ai = an - 1, bi = bn - 1;
        int carry = 0;
        string res;
        // here consider all cases until a/b all bits calculated
        while(ai >= 0 || bi >= 0) {
            int x = ai >= 0 ? a[ai--] - '0' : 0;
            int y = bi >= 0 ? b[bi--] - '0' : 0;
            int sum = x + y + carry;
            carry = sum / 2;
            res = to_string(sum % 2) + res;
        }
        return carry == 1 ? "1" + res : res;
    }

  private:
};
