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

class BinaryTreeIteratorPreOrder {
    BinaryTreeIteratorPreOrder(TreeNode* root)
    {
        if(root) {
            d_stack.push(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !d_stack.empty(); }

    /** @return the next smallest number */
    TreeNode* next()
    {
        if(!d_stack.empty()) {
            TreeNode* res = d_stack.top();
            d_stack.pop();
            if(res->right)
                d_stack.push(res->right);
            if(res->left)
                d_stack.push(res->left);
	    return res;
        }
        return nullptr;
    }

  private:
    stack<TreeNode*> d_stack;
};
