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
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        if(numCourses <= 2)
            return true;
        return bfs(numCourses, prerequisites);
    }

  private:
    bool canFinishDFS(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        unordered_map<int, vector<int> > m;
        vector<int> v(numCourses, 0);
        for(const auto& p : prerequisites) {
            m[p.first].push_back(p.second);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(hasCycle(i, m, v))
                return false;
        }
        return true;
    }

    bool hasCycle(int i, unordered_map<int, vector<int> >& m, vector<int>& v)
    {
        // within the same path, cycle deteced
        if(v[i] == -1)
            return true;
        if(v[i] == 1)
            return false;

        // mark node visited in the path
        v[i] = -1;
        for(auto k : m[i]) {
            if(hasCycle(k, m, v))
                return true;
        }
        // makr node can be traversed with no cycle
        v[i] = 1;
        return false;
    }

    bool bfs(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        vector<vector<int> > graph(numCourses, {});
        vector<int> in(numCourses, 0);
        for(const auto& p : prerequisites) {
            graph[p.second].emplace_back(p.first);
            // for those who depends on others
            ++in[p.first];
        }
        queue<int> q;
        for(size_t i = 0; i < in.size(); ++i) {
            if(in[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            for(auto d : graph[i]) {
                if(--in[d] == 0)
                    q.push(d);
            }
        }
        for(auto i : in) {
            if(in[i] != 0)
                return false;
        }
        return true;
    }
};
