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
    int kthSmallest(TreeNode* root, int k)
    {
        int res;
        inorderRecursiveImpl(root, k, res);
        return res;
    }


  private:
    void inorderRecursiveImpl(TreeNode* root, int& k, int& res)
    {
        if(k < 0)
            return;
        if(root == nullptr)
            return;
        inorderRecursiveImpl(root->left, k, res);
        --k;
        if(k == 0) {
            res = root->val;
            return;
        }
        inorderRecursiveImpl(root->right, k, res);
    }

    int iterativeImpl(TreeNode* root, const int k)
    {
        stack<TreeNode*> s;
        while(root) {
            s.emplace(root);
            root = root->left;
        }
        TreeNode* cur = nullptr;
        while(!s.empty() && k) {
            cur = s.top();
            s.pop();
            --k;
            TreeNode* candidate = cur->right;
            while(candidate) {
           s.emplace(candidate);
                candidate = candidate->left;
            }
        }
        return cur ? cur->val : numeric_limits<int>::min();
    }


    int inorderIterativeImpl(TreeNode* root, int k)
    {
        stack<TreeNode*> ss;
        ss.push(root);
        TreeNode* curNode = root;

        while(curNode->left) {
            curNode = curNode->left;
            ss.push(curNode);
        }

        while(!ss.empty()) {
            curNode = ss.top();
            ss.pop();
            --k;
            if(k == 0)
                return curNode->val;
            if(curNode->right) {
                curNode = curNode->right;
                ss.push(curNode);
                while(curNode->left) {
                    curNode = curNode->left;
                    ss.push(curNode);
                }
            }
        }
        return -1;
    }
};
