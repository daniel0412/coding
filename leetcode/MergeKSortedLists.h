/* 23. Merge k Sorted Lists
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 *describe its complexity.
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MergeKSortedLists {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        auto cmp = [](const ListNode* p1, const ListNode* p2) {return p1->val > p2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        for(auto p : lists) {
            if(p != nullptr) {
                minHeap.push(p);
            }
        }
        while(!minHeap.empty()) {
            ListNode* tmp = minHeap.top();
            minHeap.pop();
            if(tmp->next != nullptr) minHeap.push(tmp->next);
            cur->next = tmp;
            cur->next->next = nullptr;
            cur = cur->next;
        }
        return dummy.next;
    }

  private:
};
