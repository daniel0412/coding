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

class PathSumIII {
  public:
    int pathSum(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return 0;

        // without cache
        return count(root, sum) + count(root->left, sum) +
            count(root->right, sum);

        // with cache version
        unordered_map<int, int> m;
        m[0] = 1;
        return countWithCache(root, sum, 0, m);
    }

  private:
    int count(TreeNode* root, int sum, int presum)
    {
        if(root == nullptr)
            return 0;
        int cur = presum + root->val;
        return (cur == sum) + count(root->left, sum, cur) +
            count(root->right, sum, cur);
    }

    // use a map to record presum
    int countWithCache(TreeNode* root,
                       int sum,
                       int presum,
                       unordered_map<int, int>& m)
    {
        if(root == nullptr)
            return 0;
        presum += root->val;
        int res = m[presum - sum];
        ++m[presum];
        res += countWithCache(root->left, sum, presum, m) +
            countWithCache(root->right, sum, presum, m);
        --m[presum];
        return res;
    }
};
