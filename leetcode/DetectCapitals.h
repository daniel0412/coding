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

class DetectCapitals {
  public:
    bool detectCapitalUse(string word)
    {
        if(word.empty())
            return true;
        int cnt = 0;
        for(auto c : word) {
            cnt += isCap(c);
        }
        return cnt == 0 || cnt == words.size() || (cnt == 1 && isCap(word[0]));
    }

  private:
    bool isCap(char c) { return c >= 'A' && c <= 'Z'; }
};
