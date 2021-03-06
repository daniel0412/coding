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
    void findImpl(TreeNode* curnode, TreeNode* root, int k, bool& found)
    {
        if(found || !curnode)
            return;
        found = findVal(root, k - curnode->val);
        findImpl(curnode->left, root, k, found);
        findImpl(curnode->right, root, k, found);
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

    // implementation based on dfs and set
    bool findTargetII(TreeNode* tree, int k)
    {
        unordered_set<int> s;
        return dfs(root, k, s);
    }
    bool dfs(TreeNode* root, int target, unordered_set<int>& s)
    {
        if(root == nullptr) {
            return false;
        }
        int diff = target - root->val;
        if(s.count(diff))
            return true;
        s.insert(root->val);
        return dfs(root->left, target, s) || dfs(root->right, target, s);
    }
};
