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

class BSTSerialization {
  public:
    string serialize(TreeNode* root)
    {
        if(root == nullptr)
            return "";
        return to_string(root->val) + "," + serialize(root->left) +
            serialize(root->right);
    }

    TreeNode* deserialize(string data)
    {
        int startId = 0;
        return helper(data,
                      startId,
                      numeric_limits<int>::min(),
                      numeric_limits<int>::max());
    }

    TreeNode* helper(const string& data,
                     int& startId,
                     int minThresh,
                     int maxThresh)
    {
        TreeNode* root = nullptr;
        if(startId >= data.size())
            return root;
        int endId = startId;
        while(data[endId] != ',')
            ++endId;
        int val = stoi(data.substr(startId, endId - startId));
        if(val < minThresh || val > maxThresh) {
            return root;
        }
        startId = endId + 1;
        root = new TreeNode(val);
        root->left = helper(data, startId, minThresh, val);
        root->right = helper(data, startId, val, maxThresh);
        return root;
    }

  private:
};
