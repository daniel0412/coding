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
    // count from top down
    int longestConsecutive(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int maxLen = 0;
        helper(root, maxLen, 0, root->val);
        return maxLen;
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

    // count from bottom up
    int longestConsecutive(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int nmax = 1;
        dfs(root, nmax);
        return nmax;
    }

    int dfs(TreeNode* root, int& nmax)
    {
        int numl = 0, numr = 0, target = root->val + 1;
        int num = 1;
        if(root->left) {
            numl = dfs(root->left, nmax);
            if(target == root->left->val) {
                num = max(num, 1 + numl);
            }
        }
        if(root->right) {
            numr = dfs(root->right, nmax);
            if(target == root->right->val) {
                num = max(num, 1 + numr);
            }
        }
        nmax = max(nmax, num);
        return num;
    }
};
