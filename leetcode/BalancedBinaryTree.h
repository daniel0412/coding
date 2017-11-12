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

class BalancedBinaryTree {
  public:
    bool isBalanced(TreeNode* root) {}

  private:
    bool buttomupImpl(TreeNode* root) { return check(root) != -1; }

    int check(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int lh = check(root->left);
        if(lh == -1)
            return -1;
        int rh = check(root->right);
        if(rh == -1)
            return -1;
        if(abs(lh - rh) > 1)
            return -1;
        return 1 + max(check(root->left), check(root->right));
    }

    bool topdonwImpl(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        if(abs(depth(root->left) - depth(root->right)) > 1)
            return false;
        return topdonwImpl(root->left) && topdonwImpl(root->right);
    }

    int depth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
          return 1+max(depth(root->left), depth(root->right);
    }
};
