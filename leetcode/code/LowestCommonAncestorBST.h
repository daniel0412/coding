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

class LowestCommonAncestorBST {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int minVal = min(p->val, q->val);
        int maxVal = max(p->val, q->val);
        // according to min/max value of two nodes
        // we can deicde if they belong to two separate subtree
        // or same left/right subtree
        if(root->val > minVal && root->val < maxVal)
            return root;
        if(root->val < minVal)
            return lowestCommonAncestor(root->right, p, q);
        if(root->val > maxVal)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }

  private:
};
