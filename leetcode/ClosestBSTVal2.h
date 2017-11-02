/*  272 Closest Binary Search Tree Value II
 *
 * Given a non-empty binary search tree and a target value, find k values in
 *the BST that are closest to the target.
 *
 * Note:
 *
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that
 *are closest to the target.
 *
 *
 *  Follow up:
 *  Assume that the BST is balanced, could you solve it in less than O(n)
 *runtime (where n = total nodes)?
 *
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
#include <queue>
#include <functional>
#include <utility>
#include <utils.h>

using namespace std;

class ClosestBSTVal2 {
  public:
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        inorder(root, target, k);
        vector<int> res;
        while(!d_maxHeap.empty()) {
            res.push_back(d_maxHeap.top().second);
            d_maxHeap.pop();
        }
        return res;
    }

  private:
    void inorder(TreeNode* root, double target, int k)
    {
        if(root == nullptr)
            return;
        double diff = abs(root->val - target);
        if(d_maxHeap.size() < k) {
            d_maxHeap.push(make_pair(diff, root->val));
        }
        else if(diff < d_maxHeap.top().first) {
            d_maxHeap.pop();
            d_maxHeap.push(make_pair(diff, root->val));
        }
        inorder(root->left, target, k);
        inorder(root->right, target, k);
    }
    typedef pair<double, int> DiffPair;
    class Comp {
      public:
        bool operator()(const DiffPair& a, const DiffPair& b)
        {
            return a.first < b.first;
        }
    };
    priority_queue<DiffPair, vector<DiffPair>, Comp> d_maxHeap;


  private:
    vector<int> twoStackImpl(TreeNode* root, double target, int k)
    {
        stack<TreeNode *> pre, suc;
        while(root) {
            if(root->val <= target) {
                pre.push(root);
                root = root->right;
            }
            else {
                suc.push(root);
                root = root->left;
            }
        }
        vector<int> res;

        while(k-- > 0) {
            if(suc.empty() ||
               (!pre.empty() && target - pre.top() < suc.top() - target)) {
                res.push_back(pre.top());
                getNextPre(pre);
            }
            else {
                res.push_back(suc.top());
                getNextSuc(suc);
            }
        }
        return res;
    }

    void getNextPre(stack<int>& pre)
    {
        TreeNode* t = pre.top();
        pre.pop();
        if(t->left) {
            pre.push(t->left);
            while(pre.top()->right)
                pre.push(pre.top()->right);
        }
    }

    void getNextSuc(stack<int>& suc)
    {
        TreeNode* t = suc.top();
        suc.pop();
        if(t->right) {
            suc.push(t->right);
            while(suc.top()->left)
                suc.push(suc.top()->left);
        }
    }
};
