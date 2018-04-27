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

class PartitionList {
  public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy, *fast = nullptr;
        while(slow->next && slow->next->val < x) {
            slow = slow->next;
        }
        if(slow->next == nullptr)
            return dummy.next;
        fast = slow->next;
        while(fast->next) {
            if(fast->next->val >= x) {
                fast = fast->next;
            }
            else {
                ListNode* nodeToChange = fast->next;
                fast->next = nodeToChange->next;
                nodeToChange->next = slow->next;
                slow->next = nodeToChange;
                slow = nodeToChange;
            }
        }
        return dummy.next;
    }

  private:
};
