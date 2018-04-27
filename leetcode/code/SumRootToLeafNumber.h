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

class SumRootToLeafNumber {
  public:
    int sumNumbers(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int total = 0;
        helper(root, 0, total);
        return total;
    }

  private:
    void helper(TreeNode* root, int curSum, int& total)
    {
        if(root == nullptr)
            return;
        curSum += root->val;
        if(root->left == nullptr && root->right == nullptr) {
            total += curSum;
            return;
        }
        curSum *= 10;
        if(root->left)
            helper(root->left, curSum, total);
        if(root->right)
            helper(root->right, curSum, total);
    }
};
