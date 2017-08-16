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

class FindModeInBST {
  public:
    vector<int> findMode(TreeNode* root)
    {
        vector<int> res;
        int maxSum = 0, curSum = 0, preVal = INT_MIN;
        inorder(root, maxSum, curSum, preVal, res);
        return res;
    }

  private:
    void inorder(const TreeNode* root,
                 int& maxSum,
                 int& curSum,
                 int& preVal,
                 vector<int>& res)
    {
        if(root == nullptr)
            return;
        inorder(root->left, maxSum, curSum, preVal, res);
        if(root->val == preVal) {
            ++curSum;
        }
        else {
            preVal = root->val;
            curSum = 1;
        }
        if(curSum >= maxSum) {
            if(curSum > maxSum) {
                res.clear();
                maxSum = curSum;
            }
            res.push_back(root->val);
        }

        inorder(root->right, maxSum, curSum, preVal, res);
    }
};
