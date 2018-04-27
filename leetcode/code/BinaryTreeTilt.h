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

class BinaryTreeTilt {
  public:
    int findTilt(TreeNode* root)
    {
        int tilt = 0;
        sumOfSubtree(root, tilt);
        return tilt;
    }

  private:
    int sumOfSubtree(TreeNode* root, int& tilt)
    {
        if(!root)
            return 0;
        int leftSum = sumOfSubtree(root->left, tilt);
        int rightSum = sumOfSubtree(root->right, tilt);
        tilt += (abs(leftSum - rightSum));
        return leftSum + rightSum + root->val;
    }
};
