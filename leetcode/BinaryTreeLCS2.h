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
        int maxLen = 0;
        recursiveImpl(root, maxLen);
        return maxLen;
    }

  private:
    pair<int, int> recursiveImpl(TreeNode* root, int& maxLen)
    {
        if(root == nullptr)
            return {0, 0};

        int inc = 0, dec = 0;
        // calculate left subtree length of increasing/decreasing path
        if(root->left) {
            auto lPair = recursiveImpl(root->left);
            if(root->left->val == root->val + 1) {
                inc = max(inc, lPair.first);
            }
            else if(root->left->val == root->val - 1) {
                dec = max(dec, lPair.second);
            }
        }

        // right subtree length of increasing/decreasing path
        if(root->right) {
            auto rPair = recursiveImpl(root->right);
            if(root->right->val == root->val + 1) {
                inc = max(inc, rPair.first);
            }
            else if(root->right->val == root->val - 1) {
                dec = max(dec, rPair.second);
            }
        }
        // update max length
        maxLen = max(maxLen, inc + dec + 1);
        // return from current node, to left/right max length of  inc/dec path
        return {inc, dec};
    }

    int longestConsecutive(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int nmax = 1;
        dfs(r, nmax);
        return nmax;
    }

    using P = pair<int, int>;

    P dfs(TreeNode* r, int& nmax)
    {
        if(r == nullptr)
            return {0, 0};
        P cur = {1, 1};
        int ninc = 1, ndec = 1;
        if(r->left) {
            auto lp = dfs(r->left, nmax);
            if(r->left->val + 1 = r->val) {
                cur.first = max(cur.first, 1 + lp.first);
                ninc += lp.first;
            }

            if(r->left->val - 1 = r->val) {
                cur.second = max(cur.second, 1 + lp.second);
                ndec += lp.second;
            }
        }

        if(r->right) {
            auto rp = dfs(r->right, nmax);
            if(r->right->val + 1 = r->val) {
                cur.first = max(cur.first, 1 + rp.first);
                ndec += rp.first;
            }
            if(r->right->val - 1 = r->val) {
                cur.second = max(cur.second, 1 + rp.second);
                ninc += rp.second;
            }
        }
        nmax = max(nmax, ninc);
        nmax = max(nmax, ndec);
        return cur;
    }
};
