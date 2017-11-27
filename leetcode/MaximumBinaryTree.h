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

class MaximumBinaryTree {
  public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.empty())
            return nullptr;
        return iterative(nums);
        //return recursive(nums, 0, nums.size() - 1);
    }

  private:
    TreeNode* recursive(const vector<int>& nums, int start, int end)
    {
        if(start > end)
            return nullptr;
        int maxId = start;
        for(size_t i = start + 1; i <= end; ++i) {
            if(nums[i] > nums[maxId]) {
                maxId = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxId]);
        root->left = recursive(nums, start, maxId - 1);
        root->right = recursive(nums, maxId + 1, end);
        return root;
    }

    TreeNode* iterative(const vector<int>& nums)
    {
        // works as a stack
        vector<TreeNode*> nodes;
        for(auto n : nums) {
            TreeNode* cur = new TreeNode(n);
            while(!nodes.empty() && nodes.back()->val < n) {
                cur->left = nodes.back();
                nodes.pop_back();
            }
            if(!nodes.empty()) {
                nodes.back()->right = cur;
            }
            nodes.push_back(cur);
        }
        return nodes.front();
    }
};
