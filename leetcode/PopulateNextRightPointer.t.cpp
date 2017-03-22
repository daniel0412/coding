#include "gtest/gtest.h"
#include "PopulateNextRightPointer.h"

TEST(PopulateNextRightPointer, PopulateNextRightPointer)
{
    PopulateNextRightPointer sol;

    // build up the perfect binay tree
    //         1
    //     2       3
    //  4     5 6    7

    int i = 1;
    TreeLinkNode* root = new TreeLinkNode(i++);
    stack<TreeLinkNode*> mystack;
    mystack.push(root);
    TreeLinkNode* cur = nullptr;
    while(i < 8) {
        cur = mystack.top();
        mystack.pop();
        TreeLinkNode* left = new TreeLinkNode(i++);
        TreeLinkNode* right = new TreeLinkNode(i++);
        cur->left = left;
        cur->right = right;
        mystack.push(left);
        mystack.push(right);
    }

    ASSERT_EQ(i, 8);

    sol.connect(root);

    TreeLinkNode* leftMost = root;
    cur = root;
    i = 1;
    while(leftMost) {
        leftMost = leftMost->left;
        while(cur) {
            EXPECT_EQ(i++, cur->val);
            // 'tmp' is used to free the memory
            TreeLinkNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        cur = leftMost;
    }
}
