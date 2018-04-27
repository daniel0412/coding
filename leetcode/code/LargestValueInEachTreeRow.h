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

class LargestValueInEachTreeRow {
  public:
      vector<int> largestValues(TreeNode* root) {
          vector<int> res;
          if(root == nullptr) return res;
          int maxVal = INT_MIN;
          queue<TreeNode*> q;
          q.push(root);
          q.push(nullptr);
          while(!q.empty()) {
              if(q.front() == nullptr) {
                  q.pop();
                  if(!q.empty()) q.push(nullptr);
                  res.push_back(maxVal);
                  maxVal = INT_MIN;
                  continue;
              }
              TreeNode* cur = q.front();
              q.pop();
              maxVal = max(maxVal, cur->val);
              if(cur->left) q.push(cur->left);
              if(cur->right) q.push(cur->right);
          }
          return res;
      }
  private:
};
