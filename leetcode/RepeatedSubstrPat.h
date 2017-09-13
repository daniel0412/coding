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

class RepeatedSubstrPat {
  public:
    bool repeatedSubstringPattern(string s)
    {
        if(s.size() <= 1)
            return false;
        for(int i = 2; i <= s.size(); ++i) {
            if(s.size() % i == 0) {
                int len = s.size() / i;
                string tmp = s.substr(0, len);
                string a;
                for(int k = 0; k < i; ++k) {
                    a += tmp;
                }
                if(a == s)
                    return true;
            }
        }
        return false;
    }

  private:
};
