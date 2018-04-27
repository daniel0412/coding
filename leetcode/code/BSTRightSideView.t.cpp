#include "gtest/gtest.h"
#include "BSTRightSideView.h"

TEST(BSTRightSideView, BSTRightSideView) 
{
    BSTRightSideView sol;

    // build  the following binary tree
    //             1
    //      2               3
    //          4       5
    //              6
    //
    int i = 0;
    TreeNode *root = new TreeNode(++i);
    root->left = new TreeNode(++i);
    root->right = new TreeNode(++i);
    root->left->right = new TreeNode(++i);
    root->right->left = new TreeNode(++i);
    root->left->right->right = new TreeNode(++i);

    auto res = sol.rightSideView(root);
    EXPECT_EQ(res.size(), 4);
    vector<int> target = {1,3,5,6};
    for(int i = 0; i < target.size(); ++i) {
        EXPECT_EQ(target[i], res[i]);
    }

    // free all memory
    stack<TreeNode*> mystack;
    if(root) mystack.push(root);
    while(!mystack.empty()) {
        TreeNode *tmp = mystack.top();
        mystack.pop();
        if(tmp->left) mystack.push(tmp->left);
        if(tmp->right) mystack.push(tmp->right);
        delete tmp;
    }
}
