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

class KthSmallestElementInBST {
  public:
    int kthSmallest(TreeNode* root, int k) { return helper(root, k)->val; }

  private:
    TreeNode* helper(TreeNode* root, int& k)
    {
        if(root == nullptr)
            return root;
        TreeNode* leftNode = helper(root->left, k);
        if(leftNode)
            return leftNode;
        if(--k == 0)
            return root;
        return helper(root->right, k);
    }
};
