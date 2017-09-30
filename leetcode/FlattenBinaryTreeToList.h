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

class FlattenBinaryTreeToList {
  public:
    void flatten(TreeNode* root) { iterativeImpl(root); }

  private:
    TreeNode* recursiveImpl(TreeNode* root)
    {
        if(root == nullptr)
            return nullptr;
        if(root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode* tmpRight = root->right;
        TreeNode* leftLastNode = root->left ? impl(root->left) : nullptr;
        TreeNode* rightLastNode = root->right ? impl(root->right) : nullptr;
        root->right = root->left ? root->left : tmpRight;
        root->left = nullptr;
        if(leftLastNode) {
            leftLastNode->left = nullptr;
            leftLastNode->right = tmpRight;
        }
        return rightLastNode ? rightLastNode : leftLastNode;
    }

    void iterativeImpl(TreeNode* root) {
	while(root) {
	    // if both left/right exist, find parent of the right child
	    if(root->left && root->right) {
		TreeNode* l = root->left;
		while(l->right) {
		    l = l->right;
		}
		l->right = root->right;
	    }
	    // if only left exist, just change to right
	    if(root->left) {
		root->right = root->left;
	    }
	    root->left = nullptr;
	    root = root->right;
	}

    }
};
