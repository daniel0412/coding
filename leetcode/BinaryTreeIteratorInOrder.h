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

class BinaryTreeIteratorInOrder {
  public:
    BinaryTreeIteratorInOrder(TreeNode* root)
    {
        while(root) {
            d_stack.push(root);
            root = root->left;
        }
    }

    bool hasNext(){return !d_stack.empty()};

    TreeNode* next()
    {
        if(!d_stack.empty()) {
            TreeNode* res = s.top();
            s.pop();
            TreeNoe* cur = res->right;
            while(cur) {
                d_stack.push(cur);
                cur = cur->left;
            }
            return res;
        }
        return nullptr;
    }

  private:
    stack<TreeNode*> d_stack;
};
