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

class DiameterBinaryTree {
  public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int maxNode = 0;
        helper(root, maxNode);
        // diameter is the length of edges, thus -1
        return maxNode > 1 ? maxNode - 1 : 0;
    }

  private:
    int helper(TreeNode* root, int& maxNode)
    {
        if(root == nullptr) {
            return 0;
        }
        int leftMaxNode = helper(root->left, maxNode);
        int rightMaxNode = helper(root->right, maxNode);
        // max number of nodes
        int sumNode = leftMaxNode + rightMaxNode + 1;
        maxNode = (sumNode > maxNode) ? sumNode : maxNode;
        return 1 + max(leftMaxNode, rightMaxNode);
    }
};
