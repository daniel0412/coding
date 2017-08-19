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

class ConvertBST2GreaterTree {
  public:
    TreeNode* convertBST(TreeNode* root)
    {
        int curSum = 0;
        inorder(root, curSum);
        return root;
    }

  private:
    void inorder(TreeNode* root, int& curSum)
    {
        if(root == nullptr)
            return;
        inorder(root->right, curSum);
        curSum += root->val;
        root->val = curSum;
        inorder(root->left, curSum);
    }
};
