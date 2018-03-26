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

class KthLargest {
  public:
    int findKthLargest(vector<int>& nums, int k)
    {
        if(nums.empty())
            return 0;
        return iterative(nums, k);
        // return recursive(nums, 0, nums.size()-1, k);
    }

    int partition(vector<int>& v, int s, int e)
    {
        int n = e - s + 1;
        // randomized pivot
        int p = rand() % n + s;
        swap(v[p], v[s]);
        p = s;
        int i = p + 1, j = e;
        while(i <= j) {
            if(v[i] > v[p]) {
                ++i;
            }
            else {
                swap(v[i], v[j--]);
            }
        }
        swap(v[i - 1], v[p]);
        return i - 1;
    }

    int iterative(vector<int>& v, int k)
    {
        int s = 0, e = v.size() - 1;
        int p = 0;
        while(s <= e) {
            p = partition(v, s, e);
            int n = p - s + 1;
            if(n == k)
                break;
            else if(n > k) {
                e = p - 1;
            }
            else {
                s = p + 1;
                k = k - n;
            }
        }
        return v[p];
    }

    int recursive(vector<int>& v, int s, int e, int k)
    {
        if(s == e && k == 1)
            return v[s];
        if(s < e) {
            int p = partition(v, s, e);
            int cnt = p - s + 1;
            if(cnt == k)
                return v[p];
            else if(cnt > k) {
                return recursive(v, s, p - 1, k);
            }
            else {
                return recursive(v, p + 1, e, k - cnt);
            }
        }
    }

    int pqimpl(vector<int>& nums, int k)
    {
        if(k > nums.size())
            return 0;
        priority_queue<int, vector<int>, std::greater<int> > pq;
        for(auto n : nums) {
            if(pq.size() < k) {
                pq.push(n);
            }
            else {
                if(n > pq.top()) {
                    pq.pop();
                    pq.push(n);
                }
            }
        }
        return pq.top();
    }
};
