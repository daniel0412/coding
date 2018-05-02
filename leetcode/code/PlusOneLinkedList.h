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

class PlusOneLinkedList {
  public:
      // recursive implementation
    ListNode* plusOne(ListNode* head)
    {
        if(head == nullptr)
            return head;
        int carry = recursiveImpl(head);
        if(carry > 0) {
            ListNode* l = new ListNode(carry);
            l->next = head;
            head = l;
        }
        return head;
    }

    int recursiveImpl(ListNode* cur)
    {
        int carry = 1;
        if(cur->next) {
            carry = recursiveImpl(cur->next);
        }

        int sum = cur->val + carry;
        cur->val = sum % 10;
        carry = sum / 10;
        return carry;
    }

  private:
};
