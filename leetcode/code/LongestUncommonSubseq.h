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

class LongestUncommonSubseq {
  public:
    int findLUSlength(string a, string b)
    {
        return a == b ? -1 : max(a.size(), b.size());
    }

  private:
};
