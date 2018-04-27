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

class PalindromPermutation {
  public:
    bool canPermutePalindrome(string s)
    {
        unordered_set<char> ss;
        for(auto c : s) {
            if(ss.count(c))
                ss.erase(c);
            else
                ss.insert(c);
        }
        return ss.size() < 2;
    }

  private:
};
