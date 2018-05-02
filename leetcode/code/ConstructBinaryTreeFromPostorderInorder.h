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

class ConstructBinaryTreeFromPostorderInorder {
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return build(postorder,
                     0,
                     (int) postorder.size() - 1,
                     inorder,
                     0,
                     (int) inorder.size() - 1);
    }

    TreeNode* build(const vector<int>& postorder,
                    int ps,
                    int pe,
                    const vector<int>& inorder,
                    int is,
                    int ie)
    {
        if(ps > pe || is > ie)
            return nullptr;
        if(ps == pe || is == ie) {
            return new TreeNode(postorder[ps]);
        }
        auto cur = new TreeNode(postorder[pe]);
        int i = is;
        for(; i <= ie; ++i) {
            if(inorder[i] == postorder[pe])
                break;
        }
        cur->left = build(postorder, ps, ps + i - is - 1, inorder, is, i - 1);
        cur->right = build(postorder, ps + i - is, pe - 1, inorder, i + 1, ie);
        return cur;
    }

  private:
};
