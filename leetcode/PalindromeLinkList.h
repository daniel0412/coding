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

class PalindromeLinkList {
  public:
    bool isPalindrome(ListNode* head)
    {
        if(!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        fast = slow->next;
        slow = head;
        while(fast) {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

  private:
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *c = head, *n = head->next;
        while(c) {
            c->next = p;
            p = c;
            c = n;
            if(n)
                n = n->next;
        }
        dummy.next->next = nullptr;
        return p;
    }
};
