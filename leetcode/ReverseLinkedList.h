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

class ReverseLinkedList {
  public:
      ListNode* reverseList(ListNode* head) {
      }
  private:
    ListNode* iterativeImpl(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head, *next = head->next;
        while(cur && next) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        head->next = nullptr;
        return cur;
    }

    ListNode* recursiveImpl(ListNode* head) {
        // consider head nullptr case: empty list
        if(head==nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur = recursiveImpl(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};
