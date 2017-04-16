/*  270  Closest Binary Search Tree Value
 *
 * Given a non-empty binary search tree and a target value, find the value in
 *the BST that is closest to the target.
 *
 * Note:
 *
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest
 *to the target.
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
#include <utils.h>

using namespace std;

class ClosestBSTVal {
  public:
    int closestValue(TreeNode* root, double target)
    {
        return iterativeImpl(root, target);
        // return recursiveImpl(root, target);
    }

    int recursiveImpl(TreeNode* root, double target)
    {
        int val = root->val;
        TreeNode* next = target < val ? root->left : root->right;
        if(next == nullptr)
            return val;
        int nextMin = recursiveImpl(next, target);
        return val < nextMin ? val : nextMin;
    }

    int iterativeImpl(TreeNode* root, double target)
    {
        int minVal = root->val;
        while(root) {
            if(abs(target - minVal) > abs(target - root->val)) {
                minVal = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return minVal;
    }

  private:
};
