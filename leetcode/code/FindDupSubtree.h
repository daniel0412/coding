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

class FindDupSubtree {
  public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<string, int> m;
        vector<TreeNode*> res;
        dfs(root, m, res);
        return res;
    }

  private:
    string dfs(TreeNode* root,
               unordered_map<string, int>& m,
               vector<TreeNode*>& res)
    {
        if(root == nullptr)
            return ",";
        string path = to_string(root->val) + "," + dfs(root->left, m, res) +
            dfs(root->right, m, res);
        if(m[path]++ == 1) {
            res.emplace_back(root);
        }
        return path;
    }
};
