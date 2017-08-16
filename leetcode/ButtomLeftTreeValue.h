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

class ButtomLeftTreeValue {
  public:
    int findBottomLeftValue(TreeNode* root)
    {
        int maxDepth = -1, leftVal = -1;
        dfs(root, maxDepth, leftVal, 0);
        return leftVal;
    }

  private:
    void dfs(const TreeNode* root, int& maxDepth, int& leftVal, int depth)
    {
        if(root == nullptr)
            return;
        dfs(root->left, maxDepth, leftVal, depth + 1);
        if(depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->val;
        }
        dfs(root->right, maxDepth, leftVal, depth + 1);
    }
};
