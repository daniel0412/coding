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

class InorderSuccessor {
  public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* res = nullptr;
        TreeNode* cur = root;
        while(cur) {
            if(cur->val > p->val) {
                res = cur;
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return res;
    }

  private:
};
