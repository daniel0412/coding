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

class ValidBST {
  public:
      bool isValidBST(TreeNode* root) {
          return recursiveImpl(root, LLONG_MIN, LLONG_MAX);
      }
  private:
    bool recursiveImpl(TreeNode* root, long long minVal, long long maxVal)
    {
        if(!root)
            return true;
        if(root->val <= minVal || root->val >= maxVal)
            return false;
        return recursiveImpl(root->left, minVal, maxVal) &&
            recursiveImpl(root->right, root->val, maxVal);
    }
};
