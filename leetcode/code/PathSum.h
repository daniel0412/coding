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

class PathSum {
  public:
    bool hasPathSum(TreeNode* root, int sum) { return helper(root, sum); }

  private:
    bool helper(TreeNode* root, int target)
    {
        if(root == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr) {
            return root->val == target;
        }
        int newTarget = target - root->val;
        return helper(root->left, newTarget) || helper(root->right, newTarget);
    }
};
