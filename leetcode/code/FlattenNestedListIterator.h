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

class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        for(auto iter = nestedList.rbegin(); iter != nestedList.rend();
            ++iter) {
            _s.emplace(*iter);
        }
    }

    // make sure hasNext() is called before each next() call
    int next()
    {
        int tmp = _s.top().getInteger();
        _s.pop();
        return tmp;
    }

    // hasNext() make sure the next NestedList on top of stack is always an
    // interger
    bool hasNext()
    {
        while(!_s.empty() && !_s.top().isInteger()) {
            auto t = _s.top().getList();
            _s.pop();
            for(auto iter = t.rbegin(); iter != t.rend(); ++iter) {
                _s.emplace(*iter);
            }
        }
        return !_s.empty();
    }
    stack<NestedInteger> _s;
};
