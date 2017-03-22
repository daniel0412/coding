/* 117. Populating Next Right Pointers in Each Node II
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous
 *solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class PopulateNextRightPointer2 {
  public:
    void connect(TreeLinkNode* root) { iterativeImpl(root); }

  private:
    void iterativeImpl(TreeLinkNode* root)
    {
        TreeLinkNode *leftMost = root, *cur = root, *curLeft = nullptr;
        while(leftMost) {
            // unstage leftMost
            leftMost = nullptr;
            curLeft = nullptr;

            while(cur) {
                if(cur->left) {
                    if(!leftMost)
                        leftMost = cur->left;
                    if(!curLeft) {
                        curLeft = cur->left;
                    }
                    else {
                        curLeft->next = cur->left;
                        curLeft = curLeft->next;
                    }
                }
                if(cur->right) {
                    if(!leftMost)
                        leftMost = cur->right;
                    if(!curLeft) {
                        curLeft = cur->right;
                    }
                    else {
                        curLeft->next = cur->right;
                        curLeft = curLeft->next;
                    }
                }
                cur = cur->next;
            }
            cur = leftMost;
        }
    }
};
