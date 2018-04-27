/*  339 Nested List Weight Sum
 *
 *  // This is the interface that allows for creating nested lists.
 *  // You should not implement it, or speculate about its implementation
 *  class NestedInteger {
 *     public:
 *       // Return true if this NestedInteger holds a single integer,
 *       // rather than a nested list.
 *       bool isInteger() const;
 *
 *      // Return the single integer that this NestedInteger holds,
 *      // if it holds a single integer
 *      // The result is undefined if this NestedInteger holds a nested list
 *      int getInteger() const;
 *      // Return the nested list that this NestedInteger holds,
 *      // if it holds a nested list
 *      // The result is undefined if this NestedInteger holds a single integer
 *      const vector<NestedInteger> &getList() const;
 *  };
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
class NestedInteger;

class NestedListWeightSum {
  public:
      int depthSum(vector<NestedInteger>& nestedList) {
          return recursiveCall(nestedList, 1);
      }
  private:
      int recursiveCall(vector<NestedInteger>& list, int level) {
          int sum = 0;
          for(int i = 0; i < list.size(); ++i) {
              if(list[i].isInteger()) {
                  sum += (level* list[i].getInteger());
              }else{
                  sum += recursiveCall(list[i].getList(), level+1);
              }
          }
          return sum;
      }
};
