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

class NestedListIterator {
  public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        d_stack.emplace(nestedList.begin(), nestedList.end());
    }

    int next() { return (d_stack.top().first++)->getInteger(); }

    bool hasNext()
    {
        while(!d_stack.empty()) {
            if(d_stack.top().first == d_stack.top().second) {
                d_stack.pop();
            }
            else {
                if(d_stack.top().first->isInteger()) {
                    return true;
                }
                else {
                    auto list = d_stack.top().first->getList;
                    ++d_stack.top().first;
                    d_stack.emplace(list.begin(), list.end());
                }
            }
        }
        return false;
    }

  private:
    typedef vector<NestedInteger>::iterator NestedIntegerIter;
    stack<pair<NestedIntegerIter, NestedIntegerIter> > d_stack;
};
