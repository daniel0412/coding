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
        if(data.empty())
            return nullptr;
        int startId = 0;
        return helper(data, startId);
    }

   TreeNode* helper(const string& data, int& startId)
    {
        int endId = startId;
        while(data[endId] != ',')
            ++endId;
        if(startId == endId) {
            startId = endId + 1;
            return nullptr;
        }
        int val = stoi(data.substr(startId, endId - startId));
        TreeNode* root = new TreeNode(val);
        startId = endId + 1;
        root->left = helper(data, startId);
        root->right = helper(data, startId);
        return root;
    }


   // iterative level by level serialization
    string serialize(TreeNode* root)
    {
        if(root == nullptr)
            return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr) {
                res += ",";
                continue;
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
        int startId = 0;
        root = getNextNode(data, startId);
        if(root == nullptr)
            return root;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr)
                continue;
            cur->left = getNextNode(data, startId);
            cur->right = getNextNode(data, startId);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return root;
    }

    TreeNode* getNextNode(const string& data, int& startId)
    {
        if(startId >= data.size())
            return nullptr;
        int endId = startId;
        while(data[endId] != ',')
            ++endId;

        if(endId == startId) {
            ++startId;
            return nullptr;
        }
        int val = stoi(data.substr(startId, endId - startId));
        startId = endId + 1;
        return new TreeNode(val);
    }

  private:
};
