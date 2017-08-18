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

class FindDupSubtree {
  public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<string, vector<TreeNode*> > m;
        postOrder(root, m);
        vector<TreeNode*> res;
        for(const auto& kv : m) {
            res.insert(res.end(), kv.second.begin(), kv.second.end());
        }
        return res;
    }

  private:
    string postOrder(TreeNode* root,
                     unordered_map<string, vector<TreeNode*> >& m)
    {
        if(root == nullptr)
            return "()";
        stringstream ss;
        ss << "(" << postOrder(root->left, m) << ","
           << postOrder(root->right, m) << "," << root->val;
        m[ss.str()].push_back(root);
        return ss.str();
    }
};
