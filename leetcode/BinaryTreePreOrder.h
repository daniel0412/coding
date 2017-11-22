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

class BinaryTreePreOrder {
  public:
      vector<int> preorderTraversal(TreeNode* root) {
          vector<int> res;
          iterativeImpl(root, res);
          return res;
      }
  private:
      void iterativeImpl(TreeNode* root, vector<int>& res) {
          if(root == nullptr) return;
          stack<TreeNode*> s;
          s.push(root);
          while(!s.empty()) {
              TreeNode* tmp = s.top(); s.pop();
              res.push_back(tmp->val);
              if(tmp->right) s.push(tmp->right);
              if(tmp->left) s.push(tmp->left);
          }
          return;
      }

      void recursiveImpl(TreeNode* root, vector<int>& res) {
          if(root == nullptr) return;
          res.push_back(root->val);
          recursiveImpl(root->left);
          recursiveImpl(root->right);
      }
};
