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

class MergeTwoTrees {
  public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(t1 && t2) {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            delete t2;
            return t1;
        }
        else {
            return t1 ? t1 : t2;
        }
    }

  private:
};
