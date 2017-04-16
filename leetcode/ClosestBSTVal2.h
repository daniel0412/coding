/*  272 Closest Binary Search Tree Value II
 *
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 *
 * Note:
 *
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 *
 *
 *  Follow up:
 *  Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
 *
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
#include <queue>
#include <functional>
#include <utility>
#include <utils.h>

using namespace std;

class ClosestBSTVal2 {
  public:
      vector<int> closestKValues(TreeNode* root, double target, int k) {
          inorder(root, target, k);
          vector<int> res;
          while(!d_maxHeap.empty()){
              res.push_back(d_maxHeap.top().second);
              d_maxHeap.pop();
          }
          return res;
      }
  private:
      void inorder(TreeNode* root, double target, int k) {
          if(root == nullptr) return;
          double diff = abs(root->val - target);
          if(d_maxHeap.size() < k) {
              d_maxHeap.push(make_pair(diff, root->val));
          }else if(diff < d_maxHeap.top().first) {
              d_maxHeap.pop();
              d_maxHeap.push(make_pair(diff, root->val));
          }
          inorder(root->left, target, k);
          inorder(root->right, target, k);
      }
      typedef pair<double, int> DiffPair;
      class Comp{
          public:
          bool operator()(const DiffPair& a, const DiffPair& b) {
              return a.first < b.first;
          }
      };
      priority_queue<DiffPair, vector<DiffPair>, Comp> d_maxHeap;
};
