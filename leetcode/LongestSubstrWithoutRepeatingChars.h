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

class LongestSubstrWithoutRepeatingChars {
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;
        int start = -1, end = 0;
        int maxLen = 0;
        while(end < s.size()) {
            char c = s[end];
            // use the start vs previous index to decide if it is within the current substr
            if(m.count(c) > 0 && m[c] > start) {
                start = m[c];
            }
            m[c] = end;
            maxLen = max(maxLen, end - start);
            ++end;
        }
        return maxLen;
    }

  private:
};
