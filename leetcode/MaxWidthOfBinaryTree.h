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

class MaxWidthOfBinaryTree {
  public:
    int widthOfBinaryTree(TreeNode* root)
    {
        int cnt = 0;
        if(root == nullptr)
            return cnt;
        deque<TreeNode*> q;
        q.emplace_back(root);
        while(!q.empty()) {
            // trim nullptr from back
            while(!q.empty() && q.back() == nullptr) {
                q.pop_back();
            }
            int len = q.size();
            cnt = max(cnt, len);
            // indicate if we have find left most non-empty element
            bool leftStarted = false;
            for(int i = 0; i < len; ++i) {
                if(leftStarted) {
                    q.emplace_back(q.front() ? q.front()->left : nullptr);
                    q.emplace_back(q.front() ? q.front()->right : nullptr);
                }
                else {
                    if(q.front()) {
                        if(q.front()->left) {
                            leftStarted = true;
                            q.emplace_back(q.front()->left);
                        }
                        if(leftStarted || q.front()->right) {
                            leftStarted = true;
                            q.emplace_back(q.front()->right);
                        }
                    }
                }
                q.pop_front();
            }
        }
        return cnt;
    }

  private:
};
