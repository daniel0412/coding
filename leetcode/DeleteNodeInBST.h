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

class DeleteNodeInBST {
  public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode dummy(0);
        dummy.left = root;
        TreeNode* del = root;
        TreeNode* pre = &dummy;
        // find the key node
        while(del) {
            if(del->val == key)
                break;
            pre = del;
            del = del->val > key ? del->left : del->right;
        }
        // if cannot find key, nothing to delte
        if(!del)
            return root;
        if(pre->left && pre->left->val == key)
            pre->left = deleteFoundNode(del);
        else
            pre->right = deleteFoundNode(del);
        return dummy.left;
    }

  private:
    TreeNode* deleteFoundNode(TreeNode* del)
    {
        if(del->left && del->right) {
            TreeNode *pre = del, *swap = del->right;
            while(swap) {
                pre = swap;
                swap = swap->left;
            }
            swap->left = del->left;
            if(pre != del) {
                pre->left = swap->right;
                swap->right = del->right;
            }
            return swap;
        }
        else if(del->left) {
            return del->left;
        }
        else if(del->right) {
            return del->right;
        }
        else {
            return nullptr;
        }
    }
};
