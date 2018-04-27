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

class TaskWithPriorityAndDependency {
  public:
    // n: total tasks numbered 0, 1, ... , n-1
    // graph: task id -> (priority, set_of(dependent task ids))
    vector<int> completeTaskOrder(
        int n, unordered_map<int, pair<int, unordered_set<int> > >& graph)
    {
        // tracking number of dependencies per task
        vector<int> degrees(n, 0);
        // locate what tasks depend on a given task
        unordered_map<int, unordered_set<int> > dependency;
        for(const auto& kv : graph) {
            degrees[kv.first] += kv.second.second.size();
            for(auto id : kv.second.second) {
                dependency[id].insert(kv.first);
            }
        }

        // comparator for min priority queue
        // priority number lower: priority high
        auto comp =
            [&graph](int i, int j) { return graph[i].first > graph[j].first; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(int i = 0; i < n; ++i) {
            if(degrees[i] == 0) {
                pq.push(i);
            }
        }

        vector<int> res;
        while(!pq.empty()) {
            int id = pq.top();
            pq.pop();
            for(auto i : dependency[id]) {
                if(--degrees[i] == 0) {
                    pq.push(i);
                }
            }
            res.push_back(id);
        }
    /* to detect if cycle exists
         * for(auto d : degrees) {
         * if(d != 0) {// cycle exist
         *  res = {};
         *  break;
         * }
         * }
    */
        return res;
    }

  private:
};

int main()
{
    // graph: 5 tasks
    // 0->(3, (1,2,3,4))
    // 1->(3, (2, 3))
    // 2->(1, (4))
    // 3->(2, (4))
    // 4->(3, ())
    // ordering: 4, 2, 3, 1, 0
    // to test prioirty: switch the priority for task 2 and 3

    int n = 5;
    unordered_map<int, pair<int, unordered_set<int> > > graph;
    graph[0] = {3, {1, 2, 3, 4}};
    graph[1] = {3, {2, 3}};
    graph[2] = {1, {4}};
    graph[3] = {2, {4}};
    graph[4].first = 3;
    TaskWithPriorityAndDependency impl;
    auto res = impl.completeTaskOrder(n, graph);
    for(auto r : res) {
        cout << r << endl;
    }
    return 0;
}
