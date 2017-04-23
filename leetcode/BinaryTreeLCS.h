/*  298 Binary Tree Longest Consecutive Sequence
 *
 * Given a binary tree, find the length of the longest consecutive sequence
 *path.
 *
 *
 *
 *  The path refers to any sequence of nodes from some starting node to any
 *node in the tree along the parent-child connections. The longest consecutive
 *path need to be from parent to child (cannot be the reverse).
 *
 *  For example,
 *
 *     1
 *       \
 *        3
 *       / \
 *      2   4
 *           \
 *            5
 * Longest consecutive sequence path is 3-4-5, so return 3.
 *
 *       2
 *        \
 *         3
 *        /
 *       2
 *      /
 *     1
 * Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class BinaryTreeLCS {
  public:
    int longestConsecutive(TreeNode* root)
    {
        int maxLen = 0;
        recursiveImpl(nullptr, root, maxLen, 0);
        return maxLen;
    }

  private:
    void recursiveImpl(TreeNode* parent,
                       TreeNode* child,
                       int& maxLen,
                       int curLen)
    {
        if(child == nullptr) {
            return;
        }
        if(parent == nullptr || (child->val - 1 != parent->val)) {
            curLen = 1;
        }
        else {
            ++curLen;
        }
        maxLen = maxLen > curLen ? maxLen : curLen;
        recursiveImpl(child, child->left, maxLen, curLen);
        recursiveImpl(child, child->right, maxLen, curLen);
    }
};
