/* 199. Binary Tree Right Side View
 *
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTRightSideView {
  public:
      vector<int> rightSideView(TreeNode* root) {
          vector<int> res;
          //dfsImpl(root, res, 1);
          iterativeImpl(root, res);
          return res;
      }

    private:
      void dfsImpl(TreeNode* root, vector<int>& res, int level) {
          if(!root) return;
          if(res.size() < level) res.push_back(root->val);
          else res[level-1] = root->val;
          dfsImpl(root->left, res, level+1);
          dfsImpl(root->right, res, level+1);
      }

      void iterativeImpl(TreeNode *root, vector<int>& res) {
          if(!root) return;
          queue<TreeNode*> myque;
          myque.push(root);
          int qSize = myque.size();
          while(qSize) {
              TreeNode *cur = myque.front();
              myque.pop();
              --qSize;

              if(cur->left) myque.push(cur->left);
              if(cur->right) myque.push(cur->right);

              if(qSize == 0) {
                  res.push_back(cur->val);
                  qSize = myque.size();
              }
          }
      }
};
