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

class PathSumII {
  public:
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector<vector<int> > res;
        if(root == nullptr)
            return res;
        vector<int> path;
        helper(root, sum, pathres);
        return res;
    }

  private:
    void helper(TreeNode* root,
                int target,
                vector<int>& path,
                vector<vector<int> >& res)
    {
        // if this is a leaf node
        if(root->left == nullptr && root->right == nullptr) {
            if(target == root->val) {
                path.push_back(root->val);
                res.emplace_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);
        int newTarget = target - root->val;
        if(root->left)
            helper(root->left, newTarget, path, res);
        if(root->right)
            helper(root->right, newTarget, path, res);
        path.pop_back();
    }
};
