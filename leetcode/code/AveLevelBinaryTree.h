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

class AveLevelBinaryTree {
  public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int cnt = 0;
        long long sum = 0;

        while(!q.empty()) {
            if(q.front() == nullptr) {
                q.pop();
                if(!q.empty())
                    q.push(nullptr);
                if(cnt > 0) {
                    res.push_back(sum * 1.0 / cnt);
                }
                sum = 0;
                cnt = 0;
                continue;
            }
            TreeNode* cur = q.front();
            q.pop();
            ++cnt;
            sum += cur->val;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return res;
    }

  private:
};
