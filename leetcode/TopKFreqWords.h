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

class TopKFreqWords {
  public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> m;
        for(const auto& w : words) {
            ++m[w];
        }
        auto comp =
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second > b.second || (a.second == b.second && compstr(b.first, a.first);
            };
        priority_queue<pair<string, int>,
                       vector<pair<string, int> >,
                       decltype(comp)> q(comp);

        for(const auto& kv : m) {
            if(q.size() < k) {
                q.emplace(kv.first, kv.second);
            }
            else {
                if(kv.second > q.top().second ||
                   (kv.second == q.top().second &&
                    compstr(kv.first, q.top().first))) {
                    q.pop();
                    q.emplace(kv.first, kv.second);
                }
            }
        }

        vector<string> res(k);
        int i = k;
        while(!q.empty()) {
            res[--i] = q.top().first;
            q.pop();
        }
        return res;
    }

  private:
    bool compstr(const string& s1, const string& s2)
    {
        int i = 0;
        while(i < s1.size() && i < s2.size()) {
            if(s1[i] != s2[i])
                return s1[i] < s2[i];
            ++i;
        }
        return s1.size() < s2.size();
    }
};
