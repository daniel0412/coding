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
            vector<int> orders;
            if(!dfsImpl(graph, visited, orders, i))
                return vector<int>();
            vector<int>::const_reverse_iterator iter = orders.rbegin();
            for(; iter != orders.rend(); ++iter) {
                res.push_back(*iter);
            }
        }
        return res;
    }

    bool dfsImpl(const vector<vector<int> >& graph,
                 vector<int>& visited,
                 vector<int>& orders,
                 int i)
    {
        if(visited[i] == -1)
            return false;
        if(visited[i] == 1)
            return true;
        visited[i] = -1;
        orders.push_back(i);
        for(auto d : graph[i]) {
            if(!dfsImpl(graph, visited, orders, d))
                return false;
        }
        visited[i] = 1;
        return true;
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
                --degrees[d];
                if(degrees[d] == 0)
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
