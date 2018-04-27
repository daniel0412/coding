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

class SlidingWindowMax {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {}

    vector<int> o1impl(const vector<int>& nums, int k)
    {
        if(nums.empty() || k == 0)
            return {};
        vector<int> res;
        deque<int> q;
        int i = 0;
        while(i < nums.size()) {
            // remove prior elements outside of the window from the front
            while(!q.empty() && q.front() + k <= i)
                q.pop_front();
            // remove elements smaller than current elements
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if(i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
            ++i;
        }
        return res;
    }

    vector<int> pqimpl()
    {
        if(nums.empty() || k == 0)
            return {};
        vector<int> res;
        auto comp = [&nums](int i, int j) {
            return nums[i] < nums[j] || (nums[i] == nums[j] && i > j);
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        int i = 0;
        while(i < k) {
            pq.push(i++);
        }
        while(i <= nums.size()) {
            res.push_back(nums[pq.top()]);
            while(!pq.empty() && pq.top() + k <= i) {
                pq.pop();
            }
            pq.push(i++);
        }
        return res;
    }

  private:
};
