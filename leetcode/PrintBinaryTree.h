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

class PrintBinaryTree {
  public:
    vector<vector<string> > printTree(TreeNode* root)
    {
        int k = height(root);
        int numCol = pow(2, k) - 1;
        vector<vector<string> > res(k, vector<string>(numCol, ""));
        populate(root, 0, numCol - 1, 0, res);
        return res;
    }

  private:
    int height(TreeNode* r)
    {
        if(!r)
            return 0;
        return max(height(r->left), height(r->right)) + 1;
    }
    void populate(TreeNode* root,
                  int left,
                  int right,
                  int level,
                  vector<vector<string> >& res)
    {
        if(!root || left > right)
            return;
        int mid = left + (right - left) / 2;
        res[level][mid] = to_string(root->val);
        populate(root->left, left, mid - 1, level + 1, res);
        populate(root->right, mid + 1, right, level + 1, res);
    }
};
