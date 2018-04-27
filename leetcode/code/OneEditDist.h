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

class OneEditDist {
  public:
    bool isOneEditDistance(string s, string t)
    {
        int sLen = s.size(), tLen = t.size();
        if(abs(sLen - tLen) > 1)
            return false;
        for(int i = 0; i < min(sLen, tLen); ++i) {
            if(s[i] != t[i]) {
                if(sLen == tLen) {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else {
                    if(sLen > tLen)
                        return s.substr(i + 1) == t.substr(i);
                    else
                        return s.substr(i) == t.substr(i + 1);
                }
            }
        }
        return true;
    }

  private:
};
