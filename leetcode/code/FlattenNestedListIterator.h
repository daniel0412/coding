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

/**
 *  * // This is the interface that allows for creating nested lists.
 *   * // You should not implement it, or speculate about its implementation
 *    * class NestedInteger {
 *     *   public:
 *      *     // Return true if this NestedInteger holds a single integer,
 * rather than a nested list.
 *       *     bool isInteger() const;
 *        *
 *         *     // Return the single integer that this NestedInteger holds, if
 * it holds a single integer
 *          *     // The result is undefined if this NestedInteger holds a
 * nested list
 *           *     int getInteger() const;
 *            *
 *             *     // Return the nested list that this NestedInteger holds,
 * if it holds a nested list
 *              *     // The result is undefined if this NestedInteger holds a
 * single integer
 *               *     const vector<NestedInteger> &getList() const;
 *                * };
 *                 */
class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        for(auto iter = nestedList.rbegin(); iter != nestedList.rend();
            ++iter) {
            d_s.push(*iter);
        }
    }

    int next()
    {
        NestedInteger t = d_s.top();
        d_s.pop();
        return t.getInteger();
    }

    bool hasNext()
    {
        while(!d_s.empty()) {
            NestedInteger nl = d_s.top();
            d_s.pop();
            if(nl.isInteger()) {
                true;
            }
            else {
                auto& t = nl.getList();
                for(auto iter = t.rbegin(); iter != t.rend(); ++iter) {
                    d_s.push(*iter);
                }
            }
        }
        return false;
    }

    stack<NestedInteger> d_s;
};

