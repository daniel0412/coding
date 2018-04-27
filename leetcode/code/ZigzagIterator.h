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

class ZigzagIterator {
  public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if(v1.begin() != v1.end()) {
            d_q.emplace_back({v1.begin(), v1.end()});
        }

        if(v2.begin() != v2.end()) {
            d_q.emplace_back({v2.begin(), v2.end()});
        }
    }

    int next()
    {
        auto b = d_q.front().frist;
        auto e = d_q.front().second;
        d_q.pop();
        if(b + 1 != e)
            d_q.emplace({b + 1, e});
        return *b;
    }

    bool hasNext() { return !d_q.empty(); }

  private:
    queue<pair<vector<int>::iterator, vector<int>::iterator> > d_q;
};
