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

class ConvertSortedListToBST {
  public:
    // recursion from root to leaves
    // O(nlog(n)) solution T(n) = 2T(n/2) + O(n), O(n) to loop over the list
    TreeNode* sortedListToBST(ListNode* head)
    {
        return recursiveImpl(head, nullptr);
    }

    TreeNode* recursiveImpl(ListNode* head, ListNode* tail)
    {
        if(head == tail)
            return nullptr;
        if(head->next == tail) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode *mid = head, *tmp = head;
        // attention to this stopping criteria
        while(tmp != tail && tmp->next != tail) {
            mid = mid->next;
            tmp = tmp->next->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = recursiveImpl(head, mid);
        root->right = recursiveImpl(mid->next, tail);
        return root;
    }

    // recursion to construct from leaves to root
    // O(n) solution: T(n) = 2T(n/2) + const 
    TreeNode* sortedListToBST(ListNode* head)
    {
        int n = 0;
        ListNode* cur = head;
        while(cur) {
            ++n;
            cur = cur->next;
        }
        cur = head;
        return impl(cur, n);
    }

    TreeNode* impl(ListNode*& cur, int n)
    {
        if(n == 0)
            return nullptr;
        TreeNode* left = impl(cur, n / 2);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        // ATTENTION: here n-n/2-1 since root also takes one node
        TreeNode* right = impl(cur, n - n / 2 - 1);
        root->left = left;
        root->right = right;
        return root;
    }
};
