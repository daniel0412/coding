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

class BinaryTreeToDoubleLinkedList {
  public:
    using HeadTailPtr = pair<TreeNode*, TreeNode*>;
    TreeNode* flatten(TreeNode* root)
    {
        HeadTailPtr ptr = helper(root);
        return ptr.first;
    }

  private:
    // or just return root, then 
    // lefttree: move right to find the tail of left subtree
    // righttree: move left to find the head of the right subtree
    HeadTailPtr helper(TreeNode* root)
    {
        if(root == nullptr)
            return HeadTailPtr{nullptr, nullptr};
        if(root->left == nullptr && root->right == nullptr)
            return HeadTailPtr{root, root};
        HeadTailPtr ptrs1 = helper(root->left);
        HeadTailPtr ptrs2 = helper(root->right);
        TreeNode *head = nullptr, *tail = nullptr;
        if(ptr1.second) {
            ptr1.second->right = root;
            root->left = ptr1.second;
            head = ptr1.first;
        }
        if(!head) head = root;
        if(ptrs2.first) {
            ptrs2.->left = root;
            root->right = ptrs2.first;
            tail = ptrs2.second;
        }
        if(!tail) tail = root;
        return HeadTailPtr{ptr1.first, ptr2.second};
    }
};
