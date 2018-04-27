#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(const int val) : val(val), next(nullptr) {}
};

class TreeNode {
  public:
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

template <typename T>
T lowerBound(const vector<T>& nums, T target)
{
    int l = 0, r = nums.size() - 1, m;
    while(l <= r) {
        m = (r - l) / 2 + l;
        if(nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return l;
}

template <typename T>
T upperBound(const vector<T>& nums, T target)
{
    int l = 0, r = nums.size() - 1, m;
    while(l <= r) {
        m = (r - l) / 2 + l;
        if(nums[m] <= target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return l;
}
