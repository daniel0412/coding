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

class FlipGameII {
  public:
    bool canWin(string s)
    {
        for(int i = 1; i < s.size(); ++i) {
            // player 1 flip and palyer 2 fails after player 1's flip
            if(s[i - 1] == '+' && s[i] == '+' &&
               !canwin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
                return true;
            }
        }
        return false;
    }

  private:
};
