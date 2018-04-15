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

class BinaryTreeMaxPathSum {
  public:
    int maxPathSum(TreeNode* root)
    {
        int maxS;
        helper(root, maxS);
        return maxS;
    }

  private:
    // return max sum starting from root, plus either left path or right path
    // or nothing
    // *** cache not needed, and not suitable, since each node will only be checked once
    int helper(TreeNode* root, int& maxS)
    {
        if(root == nullptr)
            return 0;
        int leftS = helper(root->left, maxS);
        int rightS = helper(root->right, maxS);
        // updating max path sum wiht 'root' in the middle
        int curS = root->val;
        curS += max(leftS, 0);
        cur += max(rightS, 0);
        maxS = max(maxS, curS);

        return max(root->val, root->val + max(leftS, rightS));
    }
};
