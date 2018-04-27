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
        return recursiveImpl(root->left, minVal, root->val) &&
            recursiveImpl(root->right, root->val, maxVal);
    }

    bool iterativeImpl(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur) {
            s.emplace(cur);
            cur = cur->left;
        }
        long long prev = numeric_limits<long long>::min();
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            if(prev >= cur->val)
                return false;
            prev = cur->val;
            cur = cur->right;
            while(cur) {
                s.emplace(cur);
                cur = cur->left;
            }
        }
        return true;
    }
};
