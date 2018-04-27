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

class BinaryTreeInOrder {
  public:
      vector<int> inorderTraversal(TreeNode* root) {
          vector<int> res;
          iterativeImpl(root, res);
          return res;
      }
  private:

      void iterativeImpl(TreeNode* root, vector<int>& res) {
          stack<TreeNode*> s;
          while(root) {
              s.push(root);
              root = root->left;
          }
          while(!s.empty()) {
              TreeNode* tmp = s.top(); s.pop();
              res.push_back(tmp->val);
              tmp = tmp->right;
              while(tmp) {
                  s.push(tmp);
                  tmp = tmp->left;
              }
          }
      }

      void recursiveImpl(TreeNode* root, vector<int>& res) {
          if(root == nullptr) return;
          recursiveImpl(root->left);
          res.push_back(root->val);
          recursiveImpl(root->right);
      }

};
