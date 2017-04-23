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
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class BinaryTreeLCS2 {
  public:
    int longestConsecutive(TreeNode* root)
    {
        d_len = 0;
        recursiveImpl(root);
        return d_len;
    }

  private:
    int d_len;
    pair<int, int> recursiveImpl(TreeNode* parent)
    {
        pair<int, int> cPair = make_pair(0, 0);
        if(parent == nullptr)
            return cPair;

        pair<int, int> lPair = make_pair(0, 0);
        pair<int, int> rPair = make_pair(0, 0);
        cPair.first = 1;
        cPair.second = 1;

        if(parent->left) {
            lPair = recursiveImpl(parent->left);
            if(parent->left->val == parent->val + 1) {
                cPair.first = max(cPair.first, lPair.first + 1);
            }
            else if(parent->left->val == parent->val - 1) {
                cPair.second = max(cPair.second, lPair.second + 1);
            }
        }
        if(parent->right) {
            rPair = recursiveImpl(parent->right);
            if(parent->right->val == parent->val + 1) {
                cPair.first = max(cPair.first, rPair.first + 1);
            }
            else if(parent->right->val == parent->val - 1) {
                cPair.second = max(cPair.second, rPair.second + 1);
            }
        }
        d_len = max(d_len, cPair.first + cPair.second - 1);
    }
};
