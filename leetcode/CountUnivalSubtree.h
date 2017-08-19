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

class CountUnivalSubtree {
  public:
    int countUnivalSubtrees(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int cnt = 0;
        isUnivalSubtree(root, cnt);
        return cnt;
    }

  private:
    bool isUnivalSubtree(TreeNode* root, int& cnt)
    {
        if(root->left && root->right) {
            if(isUnivalSubtree(root->left) && isUnivalSubtree(root->right) &&
               root->left->val == root->right->val &&
               root->val == root->left->val) {
                ++cnt;
                return true;
            }
        }
        else if(root->left) {
            if(isUnivalSubtree(root->left) && root->val == root->left->val) {
                ++cnt;
                return true;
            }
        }
        else if(root->right) {
            if(isUnivalSubtree(root->right) && root->val == root->right->val) {
                ++cnt;
                return true;
            }
        }
        else {
            ++cnt;
            return true;
        }
        return false;
    }
};
