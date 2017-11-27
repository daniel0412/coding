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
    TreeNode* sortedListToBST(ListNode* head) { return recursiveImpl(head, nullptr); }

  private:
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
};
