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

class SubtreeOfAnotherTree {
  public:
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(s && t) {
            return isSubtree(s->left, t) || isSubtree(s->right, t) ||
                identicalTree(s, t);
        }
        else if(!s && !t) {
            return true;
        }
        else {
            return false;
        }
    }

  private:
    bool identicalTree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        if(s && t && s->val == t->val)
            return identicalTree(s->left, t->left) &&
                identicalTree(s->right, t->right);
        return false;
    }
};
