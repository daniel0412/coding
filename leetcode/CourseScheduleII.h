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

class CourseScheduleII {
  public:
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int> >& prerequisites)
    {
        return bfs(numCourses, prerequisites);
    }

  private:
    vector<int> dfs(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        vector<vector<int> > graph(numCourses, vector<int>());
        for(const auto& p : prerequisites) {
            graph[p.first].push_back(p.second);
        }
        vector<int> visited(numCourses, 0);
        vector<int> res;
        for(int i = 0; i < numCourses; ++i) {
            // already visited
            if(visited[i] == 1)
                continue;
            if(hasCycle(graph, visited, res, i))
                return {};
        }
        return res;
    }

    bool hasCycle(const vector<vector<int> >& graph,
                  vector<int>& visited,
                  vector<int>& res,
                  int i)
    {
        // mark as in the current path
        visited[i] = -1;
        for(auto d : graph[i]) {
            // if dependency already visited, skip
            if(visited[d] == 1)
                continue;
            // if already in the current path, cycle detected
            if(visited[d] == -1)
                return true;
            if(hasCycle(graph, visited, orders, d))
                return true;
        }
        // dependency check finished, mark done
        visited[i] = 1;
        // all dependency for i is checked, can push i
        orders.push_back(i);
        return false;
    }

    vector<int> bfs(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        vector<vector<int> > graph(numCourses);
        vector<int> degrees(numCourses, 0);
        vector<int> res;
        for(const auto& p : prerequisites) {
            graph[p.second].push_back(p.first);
            ++degrees[p.first];
        }
        queue<int> q;
        for(size_t i = 0; i < degrees.size(); ++i) {
            if(degrees[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto d : graph[node]) {
                if(--degrees[d] == 0)
                    q.push(d);
            }
        }
        for(auto d : degrees) {
            if(d)
                return vector<int>();
        }
        return res;
    }
};
