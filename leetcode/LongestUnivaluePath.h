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

class LongestUnivaluePath {
  public:
    int longestUnivaluePath(TreeNode* root)
    {
        int maxlen = 0;
        path(root, maxlen);
        return maxlen;
    }

    // recursive function: given a node, return the longest single sided univalue path
    // from left/right longest single sided univalue path, we can get the max length of two sided path
    int path(TreeNode* root, int& maxlen)
    {
        if(root == nullptr)
            return 0;
        int lcnt = path(root->left, maxlen);
        int rcnt = path(root->right, maxlen);
        int doubleSideLen = 0;
        int singleSideLen = 0;
        if(root->left && root->left->val == root->val) {
            doubleSideLen += lcnt;
            singleSideLen = max(singleSideLen, lcnt);
        }
        if(root->right && root->right->val == root->val) {
            doubleSideLen += rcnt;
            singleSideLen = max(singleSideLen, rcnt);
        }
        maxlen = max(maxlen, doubleSideLen);
        return 1 + singleSideLen;
    }

  private:
};
