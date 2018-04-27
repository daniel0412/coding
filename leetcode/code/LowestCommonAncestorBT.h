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

class LowestCommonAncestorBT {
  public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(!root || root==p || root==q) return root;
          TreeNode* l = lowestCommonAncestor(root->left, p, q);
          TreeNode* r = lowestCommonAncestor(root->right, p, q);
          if(l && r) return root;
          return l ? l : r;
      }
  private:
};
