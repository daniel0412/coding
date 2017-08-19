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

class MostFrequentSubtreeSum {
  public:
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        unordered_map<int, int> sumCounts;
        int maxCount = 0;
        postOrder(root, sumCounts, maxCount);
        vector<int> res;
        for(const auto& kv : sumCounts) {
            if(kv.second == maxCount) {
                res.push_back(kv.first);
            }
        }
        return res;
    }

  private:
    int postOrder(TreeNode* r,
                  unordered_map<int, int>& sumCounts,
                  int& maxCount)
    {
        if(!r)
            return 0;
        int leftSum = postOrder(r->left, sumCounts, maxCount);
        int rightSum = postOrder(r->right, sumCounts, maxCount);
        int totalSum = leftSum + rightSum + r->val;
        ++sumCounts[totalSum];
        maxCount = max(sumCounts[totalSum], maxCount);
        return totalSum;
    }
};
