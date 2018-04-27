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

class SumOfLeftLeaves {
  public:
    int sumOfLeftLeaves(TreeNode* root) {
        return impl(root, false);
    }

  private:
    int impl(TreeNode* root, bool isleft) {
        if(!root) return 0;
        if(isleft && !root->left && !root->right) return root->val;
        return impl(root->left, true) + impl(root->right, false);
    }
};
