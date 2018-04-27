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

class StringFromBinaryTree {
  public:
    string tree2str(TreeNode* t)
    {
        if(t == nullptr)
            return "";
        if(t->left && t->right)
            return to_string(t->val) + "(" + tree2str(t->left) + ")(" +
                tree2str(t->right) + ")";
        if(t->left)
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        if(t->right)
            return to_string(t->val) + "()(" + tree2str(t->right) + ")";
        return to_string(t->val);
    }

  private:
};
