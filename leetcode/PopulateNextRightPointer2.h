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
        TreeLinkNode *leftMost = root, *cur = nullptr, *curLeft = nullptr;
        // leftmost is the starting node for each level
        while(leftMost) {
            // cur starts from leftmost node
            cur = leftMost;
            // initialize leftmost and left node currently dealt with
            leftMost = nullptr;
            curLeft = nullptr;

            // each level, from left to right, and connect the child level
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
        }
    }


    void implWithQueue(TreeLinkNode* root)
    {
        if(root == nullptr)
            return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            if(q.front() == nullptr) {
                q.pop();
                continue;
            }
            else {
                TreeLinkNode* c = q.front();
                while(c != nullptr) {
                    q.pop();
                    c->next = q.front();
                    if(c->left)
                        q.push(c->left);
                    if(c->right)
                        q.push(c->right);
                    c = q.front();
                }
                q.push(nullptr);
            }
        }
    }
};
