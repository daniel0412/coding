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

class TwoSumBST {
  public:
    bool findTarget(TreeNode* root, int k)
    {
        if(root == nullptr)
            return false;
        bool found = false;
        findImpl(root, root, k, found);
        return found;
    }

  private:
    void findImpl(TreeNode* node, TreeNode* root, int k, bool& found)
    {
        if(found || !node)
            return;
        found = findVal(root, k - node->val);
        findImpl(node->left, root, k, found);
        findImpl(node->right, root, k, found);
    }
    bool findVal(TreeNode* root, int val)
    {
        if(!root)
            return false;
        if(root->val == val)
            return true;
        return root->val > val ? findVal(root->left, val) :
                                 findVal(root->right, val);
    }
};
