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

class ConstructBinaryTreeFromPreorderInorder {
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder,
                     0,
                     (int) preorder.size() - 1,
                     inorder,
                     0,
                     (int) inorder.size() - 1);
    }

    TreeNode* build(const vector<int>& preorder,
                    int ps,
                    int pe,
                    const vector<int>& inorder,
                    int is,
                    int ie)
    {
        if(ps > pe || is > ie)
            return nullptr;
        if(ps == pe || is == ie) {
            return new TreeNode(preorder[ps]);
        }
        auto cur = new TreeNode(preorder[ps]);
        int i = is;
        for(; i <= ie; ++i) {
            if(inorder[i] == preorder[ps])
                break;
        }
        cur->left = build(preorder, ps + 1, ps + i - is, inorder, is, i - 1);
        cur->right = build(preorder, ps + i - is + 1, pe, inorder, i + 1, ie);
        return cur;
    }


  private:
};
