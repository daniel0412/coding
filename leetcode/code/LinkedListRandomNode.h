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

class LinkedListRandomNode {
  public:
    LinkedListRandomNode(ListNode* head) { d_head = head; }

    // each call need to run over all the nodes
    int getRandom()
    {
        int cnt = 1, res = -1;
        ListNoe* cur = d_head;
        while(cur) {
            if(rand() % cnt == 0) {
                res = cur->val;
            }
            cur = cur->next;
            ++cnt;
        }
        return res;
    }

  private:
    ListNode* d_head;
};
