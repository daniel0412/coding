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

class BinaryTreePaths {
  public:
      vector<string> binaryTreePaths(TreeNode* root) {
          vector<string> res;
          string path;
          dfs(root, path, res);
          return res;
      }
  private:
      void dfs(TreeNode* root, string path, vector<string>& res)
      {
          if(!root) return;
          path = path + "->" + to_string(root->val);
          if(!root->left && !root->right) {
              res.emplace_back(path.substr(2);
              return;
          }
          if(root->left) {
              dfs(root->left, path, res);
          }
          if(root->right) {
              dfs(root->right, path, res);
          }

      }
};
