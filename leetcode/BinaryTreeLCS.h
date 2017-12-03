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
        if(root == nullptr)
            return 0;
        int maxLen = 0;
        return helper(root, maxLen, 0, root->val);
    }

  private:
    void helper(TreeNode* root, int& maxLen, int curLen, int target)
    {
        if(root == nullptr)
            return;
        if(root->val == target) {
            ++curLen;
        }
        else {
            curLen = 1;
        }
        maxLen = max(maxLen, curLen);
        target = root->val + 1;
        helper(root->left, maxLen, curLen, target);
        helper(root->right, maxLen, curLen, target);
    }
};
