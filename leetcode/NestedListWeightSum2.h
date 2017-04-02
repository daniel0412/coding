/*  364 Nested List Weight Sum II
 *
 * Given a nested list of integers, return the sum of all integers in the list
 *weighted by their depth.
 *
 * Each element is either an integer, or a list -- whose elements may also be
 *integers or other lists.
 *
 * Different from the previous question where weight is increasing from root to
 *leaf, now the weight is defined from bottom up. i.e., the leaf level integers
 *have weight 1, and the root level integers have the largest weight.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at
 *depth 2)
 *
 * Example 2:
 * Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2,
 *and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
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

class NestedListWeightSum2 {
    int depthSumInverse(vector<NestedInteger>& nestedList)
    {
        vector<int> levelSum;
        recursiveCall(nestedList, 0, levelSum);
        int res = 0;
        int maxDepth = levelSum.size();
        for(int i = 0; i < levelSum.size(); ++i) {
            res += levelSum[i] * (maxDepth - i);
        }
        return res;
    }

  private:
    void recursiveCall(const vector<NestedInteger> & list,
                       int depth,
                       vector<int>& levelSum)
    {
        if(depth >= levelSum.size())
            levelSum.push_back(0);
        for(auto l : list) {
            if(l.isInteger())
                levelSum[depth] += l.getInteger();
            else {
                recursiveCall(l.getList(), depth + 1, levelSum);
            }
        }
    }
};
