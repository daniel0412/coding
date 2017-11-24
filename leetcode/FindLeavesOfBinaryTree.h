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

class FindLeavesOfBinaryTree {
  public:
    vector<vector<int> > findLeaves(TreeNode* root)
    {
        vector<vector<int> > res;
        helper(root, res);
        return res;
    }

    int helper(TreeNode* root, vector<vector<int> >& res)
    {
        if(root == nullptr)
            return 0;
        int depth = max(helper(root->left, res), helper(root->right, res)) + 1;
        if(depth > res.size()) {
            res.emplace_back({});
        }
        res[depth - 1].push_back(root->val);
    }

  private:
};
