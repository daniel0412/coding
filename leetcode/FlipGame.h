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

class FlipGame {
  public:
    vector<string> generatePossibleNextMoves(string s)
    {
        vector<string> res;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == '+' && s[i - 1] == '+') {
                res.emplace_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }
        return res;
    }

  private:
};
