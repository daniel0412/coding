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

struct TreeNode {
    int val;
    vector<TreeNode*> next;
    TreeNode(int x) : val(x) {}
};

void traverseNaryTree(TreeNode* root)
{
    if(root == nullptr)
        cout << "empty tree" << endl;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->val << " ";
        for(const auto ptr : cur->next) {
            q.push(ptr);
        }
    }
}

class NaryTreeSerialization {
  public:
    string serialize(TreeNode* root)
    {
        if(root == nullptr)
            return "";
        string res = to_string(root->val) + ",";
        for(const auto ptr : root->next) {
            res += serialize(ptr);
        }
        // use this as a delimiter to indicate end of a subtree
        // since number of children for each node is undefined
        res.push_back(')');
        return res;
    }

    TreeNode* deserialize(const string s)
    {
        int curId = 0;
        return deserializeImpl(s, curId);
    }

    TreeNode* deserializeImpl(const string& s, int& curId)
    {
        // if exceed the string length, return
        if(curId >= s.size())
            return nullptr;

        int prevId = curId;
        while(isdigit(s[curId]))
            ++curId;

        // if ')' found, return
        if(prevId == curId) {
            ++curId;
            return nullptr;
        }
        // find root node
        TreeNode* root = new TreeNode(stoi(s.substr(prevId, curId - prevId)));
        ++curId;
        // loop to find all children of this root
        while(curId < s.size()) {
            TreeNode* tmp = deserializeImpl(s, curId);
            if(tmp == nullptr)
                break;
            root->next.push_back(tmp);
        }
        return root;
    }

  private:
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->next.push_back(new TreeNode(2));
    root->next.push_back(new TreeNode(3));
    root->next.push_back(new TreeNode(4));
    root->next[0]->next.push_back(new TreeNode(5));
    root->next[2]->next.push_back(new TreeNode(6));
    root->next[2]->next.push_back(new TreeNode(6));

    traverseNaryTree(root);

    NaryTreeSerialization util;
    string s = util.serialize(root);
    cout << "serialized: " << s << endl;
    TreeNode* de = util.deserialize(s);
    cout << "after deserialization: " << endl;
    traverseNaryTree(de);
    return 0;
}
