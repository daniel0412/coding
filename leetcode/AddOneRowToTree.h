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

class AddOneRowToTree {
  public:
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if(d == 1) {
            TreeNode* cur = new TreeNode(v);
            cur->left = root;
            return cur;
        }
        recursive(root, v, d - 1, 1);
        return root;
    }

  private:
    void recursive(TreeNode* root, int v, int parentLevel, int level)
    {
        if(root == nullptr)
            return;
        if(level < parentLevel) {
            recursive(root->left, v, parentLevel, level + 1);
            recursive(root->right, v, parentLevel, level + 1);
        }
        else if(level == parentLevel) {
            TreeNode* curLeft = new TreeNode(v);
            TreeNode* curRight = new TreeNode(v);
            curLeft->left = root->left;
            curRight->right = root->right;
            root->left = curLeft;
            root->right = curRight;
        }
    }
};
