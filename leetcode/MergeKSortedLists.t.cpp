#include "gtest/gtest.h"
#include "MergeKSortedLists.h"

TEST(MergeKSortedLists, EmptyListsTest)
{
    MergeKSortedLists sol;

    vector<ListNode*> lists(5, nullptr);
    ListNode* p = sol.mergeKLists(lists);
    EXPECT_EQ(p, nullptr);
}

TEST(MergeKSortedLists, FullListsTest)
{
    MergeKSortedLists sol;

    vector<ListNode*> lists;
    for(int i = 0; i < 3; ++i) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for(int j = 0; j < i + 1; ++j) {
            if(head == nullptr && cur == nullptr) {
                cur = new ListNode(i + j);
                head = cur;
            }
            else {
                cur->next = new ListNode(i + j);
                cur = cur->next;
            }
        }
        lists.push_back(head);
    }
    // printout lists
    int listId = 1;
    for(auto p : lists) {
        // cout << "list: " << listId++ << endl;
        while(p != nullptr) {
            // cout << p->val << ",";
            p = p->next;
        }
        // cout << endl;
    }
    vector<int> target = {0, 1, 2, 2, 3, 4};
    ListNode* head = sol.mergeKLists(lists);
    ListNode* p = head;
    EXPECT_NE(head, nullptr);
    int i = 0;
    while(p != nullptr) {
        EXPECT_EQ(p->val, target[i++]);
        p = p->next;
    }
    EXPECT_EQ(i, 6);

    // free the memory
    while(p != nullptr) {
        ListNode* tmp = p;
        p = p->next;
        delete tmp;
    }
}
