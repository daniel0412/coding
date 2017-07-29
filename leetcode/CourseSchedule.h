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

class CourseSchedule {
  public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        if(numCourses <= 2) return true;
        return bfs(numCourses, prerequisites);
    }

  private:
    bool dfs(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> graph(numCourses, {});
        for(const auto& p:prerequisites) {
            graph[p.first].emplace_back(p.second);
        }
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            if(!dfsImpl(graph, visited, i)) return false;
        }
        return true;
    }
    bool dfsImpl(const vector<vector<int>>& graph, vector<int>& visited, int i)
    {
        if(visited[i] == -1) return false;
        if(visited[i] == 1) return true;
        visited[i]=-1;
        for(auto c : graph[i]) {
            if(!dfsImpl(graph, visited, c)) return false;
        }
        visited[i] = 1;
        return true;
    }

    bool bfs(int numCourses, vector<pair<int,int> >& prerequisites) {
        vector<vector<int>> graph(numCourses, {});
        vector<int> in(numCourses, 0);
        for(const auto& p:prerequisites) {
            graph[p.second].emplace_back(p.first);
            ++in[p.first];
        }
        queue<int> q;
        for(size_t i = 0; i < in.size(); ++i) {
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            for(auto d: graph[i]){
                --in[d];
                if(in[d]==0) q.push(d);
            }
        }
        for(auto i : in) {
            if(in[i]!=0) return false;
        }
        return true;
    }
};
