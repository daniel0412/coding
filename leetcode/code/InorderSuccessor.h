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
    TreeNode* inorderSuccessorBST(TreeNode* root, TreeNode* p)
    {
        TreeNode* res = nullptr;
        TreeNode* cur = root;
        while(cur) {
            // keep updating the last greater element,
            // which will end up with the successor
            if(cur->val > p->val) {
                res = cur;
                cur = cur->left;
            }
            // cannot break when cur->val == p->val
            // example, successor is in the right subtree
            else {
                cur = cur->right;
            }
        }
        return res;
    }

  private:
};
