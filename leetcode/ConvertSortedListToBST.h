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
    TreeNode* sortedListToBST(ListNode* head) { return recursiveImpl(head); }

  private:
    TreeNode* recursiveImpl(ListNode* head)
    {
        if(head == nullptr)
            return nullptr;
        ListNode *first = nullptr, *mid = nullptr, *second = nullptr;
        getMid(head, first, mid, second);
        delete mid;
        TreeNode* root = new TreeNode(mid->val);
        root->left = recursiveImpl(first);
        root->right = recursiveImpl(second);
        return root;
    }

    void getMid(ListNode* head,
                ListNode*& first,
                ListNode*& mid,
                ListNode*& second)
    {
        if(head == nullptr)
            return;
        if(head->next == nullptr) {
            mid = head;
            return;
        }
        if(head->next->next == nullptr) {
            first = nullptr;
            mid = head;
            second = head->next;
            return;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        first = head;
        mid = slow->next;
        second = slow->next->next;
        slow->next = nullptr;
        return;
    }
};
