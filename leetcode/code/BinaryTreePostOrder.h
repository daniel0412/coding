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

class BinaryTreePostOrder {
  public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        iterativeImpl(root, res);
        return res;
    }

  private:
    // easier to understand, push either left or right child into stack
    // when pop, check if we should push right child
    void iterativeImpl(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left ? cur->left : cur->right;
        }
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if(!s.empty()) { // doulbe check stack is not empty
                TreeNode* parent = s.top();
                if(parent->left == cur) {
                    cur = parent->right;
                    while(cur) {
                        s.push(cur);
                        cur = cur->left ? cur->left : cur->right;
                    }
                }
            }
        }
    }


    void iterativeImpl2(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        stack<TreeNode*> s;
        s.push(root);

        TreeNode* prev = root;
        while(!s.empty()) {
            TreeNode* cur = s.top();
            if((cur->left == nullptr && root->right == nullptr) ||
               cur->left == prev || cur->right == prev) {
                res.push_back(cur->val);
                s.pop();
                prev = cur;
            }
            else {
                if(cur->right)
                    s.push(cur->right);
                if(cur->left)
                    s.push(cur->left);
            }
        }
    }
};
