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

class BinaryTreeSerialization {
    // here we provide recursive solution as well iterative solution
    // recursive: pre-order serialization
    // iterative: level-order serialization
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(root == nullptr)
            return ",";
        return to_string(root->val) + "," + serialize(root->left) +
            serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int curId= 0;
        return deserializeImpl(data, curId);
    }

    TreeNode* deserializeImpl(const string& data, int& curId)
    {
        if(curId >= data.size())
            return nullptr;

        int prevId = curId;
        while(data[curId] != ',')
            ++curId;

        if(curId == prevId) {
            ++curId;
            return nullptr;
        }
        int val = stoi(data.substr(curId, curId - prevId));
        TreeNode* root = new TreeNode(val);
        ++curId;
        root->left = deserializeImpl(data, curId);
        root->right = deserializeImpl(data, curId);
        return root;
    }


   // iterative level by level serialization
    string serialize(TreeNode* root)
    {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr) {
                res += ",";
            }
            else {
                res = res + to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }

    TreeNode* deserializeIterative(string data)
    {
        TreeNode* root = nullptr;
        if(data.empty())
            return root;
        queue<TreeNode*> q;
        int curId = 0;
        // need to get first root node to start
        root = getNextNode(data, curId);
        if(root == nullptr)
            return root;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr)
                continue;
            cur->left = getNextNode(data, curId);
            cur->right = getNextNode(data, curId);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return root;
    }

    TreeNode* getNextNode(const string& data, int& curId)
    {
        if(curId >= data.size())
            return nullptr;
        int prevId = curId;
        while(data[curId] != ',')
            ++curId;
        if(prevId == curId) {
            ++curId;
            return nullptr;
        }
        else {
            TreeNode* cur =
                new TreeNode(stoi(data.substr(prevId, curId - prevId)));
            ++curId;
            return cur;
        }
    }

  private:
};
