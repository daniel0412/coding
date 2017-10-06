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

class BSTIterator {
  public:
    BSTIterator(TreeNode* root)
    {
        while(root) {
            d_stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !d_stack.empty(); }

    /** @return the next smallest number */
    int next()
    {
        TreeNode* tmp = d_stack.top();
        d_stack.pop();
        TreeNode* cur = tmp->right;
        while(cur) {
            d_stack.push(cur);
            cur = cur->left;
        }
        return tmp->val;
    }

  private:
    stack<TreeNode*> d_stack;
};
