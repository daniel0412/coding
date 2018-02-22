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

class RelativeRanks {
  public:
    vector<string> findRelativeRanks(vector<int>& nums)
    {
        vector<string> res(nums.size());
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)>
            q(comp);
        for(int i = 0; i < nums.size(); ++i) {
            q.push(pair<int, int>{nums[i], i});
        }
        int i = 1;
        while(!q.empty()) {
            const pair<int, int>& p = q.top();
            if(i == 1) {
                res[p.second] = "Gold Medal";
            }
            else if(i == 2) {
                res[p.second] = "Silver Medal";
            }
            else if(i == 3) {
                res[p.second] = "Bronze Medal";
            }
            else {
                res[p.second] = i;
            }
            p.pop();
            ++i;
        }
        return res;
    }

  private:
    vector<string> betterImpl(vector<int>& nums)
    {
        vector<pair<int, int> > v;
        for(int i = 0; i < nums.size(); ++i) {
            v.emplace_back(pair<int, int>{i, nums[i]});
        }
        sort(v.begin(),
             v.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2) {
                 return p1.second > p2.second;
             });
        vector<string> res(v.size());
        for(int i = 0; i < v.size(); ++i) {
            res[v[i].first] = to_string(i + 1);
        }
        if(v.size() >= 1)
            res[v[0].first] = "Gold Medal";
        if(v.size() >= 2)
            res[v[1].first] = "Silver Medal";
        if(v.size() >= 3)
            res[v[2].first] = "Bronze Medal";
        return res;
    }

    vector<string> justTrackIndex(const vector<int>& nums)
    {
        int len = nums.size();
        vector<int> ids(len, 0);
        for(int i = 0; i < len; ++i) {
            ids[i] = i;
        }
        sort(ids.begin(),
             ids.end(),
             [&nums](int a, int b) { return nums[a] > nums[b]; });
        vector<string> res(len);
        if(len > 0)
            res[ids[0]] = "Gold Medal";
        if(len > 1)
            res[ids[1]] = "Silver Medal";
        if(len > 2)
            res[ids[2]] = "Bronze Medal";
        for(int i = 3; i < len; ++i) {
            res[ids[i]] = to_string(i + 1);
        }
        return res;
    }
};
