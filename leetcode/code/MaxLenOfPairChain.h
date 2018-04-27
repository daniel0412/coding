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

class MaxLenOfPairChain {
  public:
    int findLongestChain(vector<vector<int> >& pairs)
    {
        sort(pairs.begin(),
             pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int end = numeric_limits<int>::min(), len = 0;
        for(const auto& v : pairs) {
            if(v[0] > end) {
                ++len;
                end = v[1];
            }
        }
        return len;
    }

  private:
};
