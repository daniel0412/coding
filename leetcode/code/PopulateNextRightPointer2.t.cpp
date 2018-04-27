#include "gtest/gtest.h"
#include "PopulateNextRightPointer2.h"

TEST(PopulateNextRightPointer2, PopulateNextRightPointer2)
{
    PopulateNextRightPointer2 sol;

    // build up the perfect binay tree
    //         1
    //     2       3
    //  4             5

    int i = 0;
    TreeLinkNode* root = new TreeLinkNode(++i);
    TreeLinkNode* cur = root;
    root->left = new TreeLinkNode(++i);
    root->right = new TreeLinkNode(++i);
    root->left->left = new TreeLinkNode(++i);
    root->right->right = new TreeLinkNode(++i);

    ASSERT_EQ(i, 5);
    sol.connect(root);

    TreeLinkNode* leftMost = root;
    cur = root;
    i = 0;
    while(leftMost) {
        leftMost = nullptr;
        while(cur) {
            EXPECT_EQ(++i, cur->val);
            if(!leftMost && cur->left)
                leftMost = cur->left;
            if(!leftMost && cur->right)
                leftMost = cur->right;
            // 'tmp' is used to free the memory
            TreeLinkNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        cur = leftMost;
    }
    EXPECT_EQ(i, 5);
}
