/*  314 Binary Tree Vertical Order Traversal
 *
 * Given a binary tree, return the vertical order traversal of its nodes'
 *values. (ie, from top to bottom, column by column).
 *
 * If two nodes are in the same row and column, the order should be from left
 *to right.
 *
 * Examples:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its vertical order traversal as:
 *[
 *[9],
 *[3,15],
 *[20],
 *[7]
 *]
 *Given binary tree [3,9,20,4,5,2,7],
 *       _3_
 *      /   \
 *     9    20
 *    / \   / \
 *   4   5 2   7
 *return its vertical order traversal as:
 *[
 *[4],
 *[9],
 *[3,5,2],
 *[20],
 *[7]
 *]
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class BinaryTreeVOT {
  public:
    vector<vector<int> > verticalOrder(TreeNode* root)
    {
        d_left = 0;
        d_right = 0;
        recursiveImpl(root, 0);
        int i = d_left;
        vector<vector<int> > res;
        while(i <= d_right) {
            res.emplace_back(d_vot[i]);
            ++i;
        }
        return res;
    }

  private:
    void recursiveImpl(TreeNode* root, int col)
    {
        if(root == nullptr)
            return;
        d_left = d_left < col ? d_left : col;
        d_right = d_right > col ? d_right : col;
        d_vot[col].push_back(root->val);
        recursiveImpl(root->left, col - 1);
        recursiveImpl(root->right, col + 1);
    }
    // we can also use map, then no need to keep track of left/right
    unordered_map<int, vector<int> > d_vot;
    int d_left;
    int d_right;


    void iterativeImpl(TreeNode* root, vector<vector<int> >& res)
    {
        if(root == nullptr)
            return;

        map<int, vector<int> > mymap;
        queue<pair<int, TreeNode*> > myque;

        myque.emplace(0, root);
        while(!myque.empty()) {
            const auto& p = myque.front();
            mymap[p.first].push_back(p.second->val);
            if(p.second->left)
                myque.emplace(p.first - 1, p.second->left);
            if(p.second->right)
                myque.emplace(p.first + 1, p.second->right);
            myque.pop();
        }
        for(const auto& kv : mymap) {
            res.push_back(kv.second);
        }
    }
};
