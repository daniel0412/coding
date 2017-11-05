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

class EqualTreePartition {
  public:
    // corner case: [0, 1, -1], where sum = 0, and sum / 2 = sum
    bool checkEqualTree(TreeNode* root)
    {
        unordered_map<int, int> m;
        int sum = helper(root);
        if(sum == 0)
            return m[0] > 1;
        return sum % 2 == 0 && m[sum / 2];
    }

  private:
    int helper(const TreeNode* root, unordered_map<int, int>& m)
    {
        if(root == nullptr)
            return 0;
        int cur = root->val + helper(root->left, root->right, m);
        ++m[cur];
        return cur;
    }
};
