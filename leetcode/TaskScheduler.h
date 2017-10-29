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

class TaskScheduler {
  public:
    int leastInterval(vector<char>& tasks, int n)
    {
        if(tasks.empty())
            return 0;
        if(n == 0)
            return tasks.size();
        unordered_map<char, int> m;
        for(auto c : tasks) {
            ++m[c];
        }

        auto comp = [](int a, int b) { return a < b; };
        priority_queue<int, vector<int>, decltype(comp)> q(comp);
        for(const auto& kv : m) {
            q.emplace(kv.second);
        }

        int cycle = n + 1, res = 0;
        while(!q.empty()) {
            int cnt = 0;
            vector<int> tmp;
            for(int i = 0; i < cycle; ++i) {
                if(q.empty())
                    break;
                tmp.push_back(q.top() - 1);
                q.pop();
                ++cnt;
            }
            for(auto t : tmp) {
                if(t > 0)
                    q.push(t);
            }
            res += (q.empty() ? cnt : cycle);
        }
        return res;
    }

  private:
};
