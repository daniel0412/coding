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

class TopKFreqElements {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        return bucketImpl(nums, k);
    }

  private:
    // Time Complaxity: O(n)
    vector<int> bucketImpl(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        for(auto n : nums)
            ++m[n];
        vector<vector<int> > buckets(nums.size() + 1);
        for(auto& kv : m) {
            buckets[kv.second].push_back(kv.first);
        }
        vector<int> res;
        for(auto iter = buckets.rbegin(); iter != buckets.rend(); ++iter) {
            for(auto n : *iter) {
                res.push_back(n);
                if(res.size() == k)
                    return res;
            }
        }
        return res;
    }

    // Time Complexity: O(n*log(k))
    vector<int> heapImpl(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        for(auto n : nums)
            ++m[n];

        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)>
            q(comp);
        for(auto& kv : m) {
            if(q.size() < k) {
                q.emplace(kv.first, kv.second);
            }
            else {
                if(kv.second > q.top().second) {
                    q.pop();
                    q.emplace(kv.first, kv.second);
                }
            }
        }
        vector<int> res(k, 0);
        while(!q.empty()) {
            res[--k] = q.top().first;
            q.pop();
        }
        return res;
    }
};
