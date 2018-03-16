/* 116. Populating Next Right Pointers in Each Node
 *
 * Given a binary tree
 *
 *     struct TreeLinkNode {
 *           TreeLinkNode *left;
 *           TreeLinkNode *right;
 *           TreeLinkNode *next;
 *     }
 * Populate each next pointer to point to its next right node. If there is no
 *next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 *same level, and every parent has two children).
 *
 *
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class PopulateNextRightPointer {
  public:
    void connect(TreeLinkNode* root)
    {
        iterativeImpl(root);
        // recursiveImpl(root, nullptr);
    }

  private:
    void iterativeImpl(TreeLinkNode* root)
    {
        TreeLinkNode *leftMost = root, *cur = root;
        // leftmost tracks the starting node of each level
        while(leftMost) {
            // populate the next for the next level
            while(cur) {
                if(cur->left)
                    cur->left->next = cur->right;
                if(cur->next && cur->right)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            leftMost = leftMost->left;
            cur = leftMost;
        }
    }


    /**
     * @brief recursive implementaion, but considering the underlyting stack
     *used for recursion,
     *        this is not const space implementation
     *
     * @param root
     * @param next
     */
    void recursiveImpl(TreeLinkNode* root, TreeLinkNode* next)
    {
        if(root == nullptr)
            return;
        root->next = next;
        recursiveImpl(root->left, root->right);
        recursiveImpl(root->right, next);
    }
};
