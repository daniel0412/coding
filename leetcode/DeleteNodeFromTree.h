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

class DeleteNodeFromTree {
  public:
    // for current node, once deleted, need to know if its children will be removed or not
    // so post order is the way to go
    // but in postorder, need to return if current node is removed or not
    TreeNode* postOrder(TreeNode* root,
                        unordered_map<int>& dict,
                        vector<TreeNode*>& res)
    {
        if(root == nullptr)
            return nullptr;
        root->left = postOrder(root->left, dict res);
        root->right = postOrder(root->left, dict res);
        if(dict.count(root->val)) {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            return nullptr;
        }
        return root;
    }

    // this implementation keeps track of all forest roots
    // and then check again each tree
    // for each tree, if found node to remove, just remove, and push new tree nodes
    vector<TreeNode*> deleteNodes(TreeNode* root, unordered_map<int> delDict)
    {
        queue<TreeNode*> q;
        vector<TreeNode*> res;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            deleteFromOneTree(cur, dict, q);
            if(!dict.count(cur->val)) {
                res.push_back(cur);
            }
        }
        return res;
    }

    void deleteFromOneTree(TreeNode* root,
                           unordered_map<int>& dict,
                           queue<TreeNode*>& q)
    {
        if(root == nullptr)
            return;
        if(dict.count(root->val)) {
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            return;
        }
        else {
            deleteFromOneTree(root->left, key, q);
            deleteFromOneTree(root->right, key, q);
        }
    }

  private:
};
