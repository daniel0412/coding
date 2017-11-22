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

class BinaryTreeIteratorPostOrder {
  public:
    BSTIterator(TreeNode* root)
    {
        while(root) {
            d_stack.push(root);
            root = root->left ? root->left : root->right;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !d_stack.empty(); }

    /** @return the next smallest number */
    int next()
    {
        int res = -1;
        if(!d_stack.empty()) {
            TreeNode* cur = s.top();
            res = cur->val;
            s.pop();
            // double check stack is not empyty before access parent
            if(!d_stack.empty()) {
                TreeNode* parent = s.top();
                if(parent->left == cur) {
                    cur = parent->right;
                    while(cur) {
                        d_stack.push(cur);
                        cur = cur->left ? cur->left : cur->right;
                    }
                }
            }
        }
        return res;
    }

  private:
    stack<TreeNode*> d_stack;
};
