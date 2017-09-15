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

class ReverseStrII {
  public:
    string reverseStr(string s, int k)
    {
        int begin = 0, end = 0;
        while(begin < s.size()) {
            end = begin + k - 1;
            end = end < s.size() ? end : s.size() - 1;
            helper(s, begin, end);
            begin += 2 * k;
        }
        return s;
    }

  private:
    void helper(string& s, int begin, int end)
    {
        while(begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
};
