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

class NextGreaterElementIII {
  public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int len = s.ize() - 1;
        int i = len - 1;
        for(; i > 0; --i) {
            if(s[i] > s[i - 1])
                break;
        }
        if(i == 0)
            return -1;
        for(int j = len - 1; j >= i; --j) {
            if(s[j] > s[i - 1]) {
                swap(s[j], s[i - 1]);
                break;
            }
        }
        sort(s.begin() + i, s.end());
        // must check to make sure the next element is within range of int
        long long res = stoll(s);
        return res > INT_MAX ? -1 : res;
    }

  private:
};
