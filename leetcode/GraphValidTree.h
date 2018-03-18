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

class GraphValidTree {
  public:
    bool validTree(int n, vector<pair<int, int> >& edges)
    {
        return unionfind(n, edges);
        // return dfs(n, edges);
    }

  private:
    bool dfs(int n, const vector<pair<int, int> >& edges)
    {
        vector<bool> visited(n, false);
        vector<vector<int> > graph(n, vector<int>());
        for(const auto& p : edges) {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        if(!dfsImpl(graph, 0, -1, visited))
            return false;
        for(auto b : visited) {
            if(!b)
                return false;
        }
        return true;
    }
    bool dfsImpl(const vector<vector<int> >& graph,
                 int cur,
                 int parent,
                 vector<bool>& visited)
    {
        if(visited[cur])
            return false;
        visited[cur] = true;
        for(auto c : graph[cur]) {
            // make sure the same edge is only visited once
            if(c != parent)
                // if true, should continue search
                if(!dfsImpl(graph, c, cur, visited))
                    return false;
        }
        return true;
    }

    bool bfs(int n, const vector<pair<int, int> >& edges)
    {
        unordered_set<int> visited;
        vector<unordered_set<int> > graph(n, unordered_set<int>());
        for(const auto& p : edges) {
            graph[p.first].insert(p.second);
            graph[p.second].insert(p.first);
        }
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            for(auto d : graph[c]) {
                if(visited.count(d))
                    return false;
                q.push(d);
                visited.insert(d);
                // make sure `c-d`/`d-c` connection are only visited once
                graph[d].erase(c);
            }
        }
        // check only one component exists
        return visited.size() == n;
    }

    bool unionfind(int n, const vector<pair<int, int> >& edges)
    {
        vector<int> roots(n, -1);
        for(const auto& p : edges) {
            int root1 = findRoot(roots, p.first);
            int root2 = findRoot(roots, p.second);
            // make sure no cycle is formed
            if(root1 == root2)
                return false;
            roots[root1] = root2;
        }

        // make sure only one connected component
        return edges.size() + 1 = n;
    }

    int findRoot(vector<int>& roots, int i)
    {
        while(roots[i] != -1)
            i = roots[i];
        return i;
    }


    // second time implementation
    bool validTree(int n, vector<pair<int, int> >& edges)
    {
        vector<bool> v(n, false);
        unordered_map<int, vector<int> > m;
        for(const auto& e : edges) {
            m[e.first] = e.second;
            m[e.second] = e.first;
        }
        if(!dfs(0, v, m, -1))
            return false;
        for(auto vi : v) {
            if(!vi)
                return false;
        }
        return true;
    }

    bool dfs(int i,
             vector<bool>& v,
             unordered_map<int, vector<int> >& m,
             int pre)
    {
        if(i == pre)
            return true;
        if(v[i])
            return false;
        for(auto id : m[i]) {
            v[id] = true;
            if(!dfs(id, v, m i))
                return false;
        }
        return true;
    }

    bool bfs(int n, const vector<pair<int, int> >& edges)
    {
        vector<unordered_set<int> > g;
        unordered_set<int> v;
        for(const auto& e : edges) {
            g[e.first].insert(e.second);
            g[e.second].insert(e.first);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int id = q.front();
            q.pop();
            v.insert(id);
            for(auto i : g[id]) {
                if(v.count(i))
                    return false;
                q.push(i);
                g[i].erase(id);
            }
        }
        return v.size() == n;
    }

    // union find
    bool uf(int n, vector<pair<int, int> >& edges)
    {
        vector<int> p(n, 0);
        for(int i = 0; i < n; ++i)
            p[i] = i;
        int cnt = n;
        for(const auto& e : edges) {
            int x = getp(e.first, p);
            int y = getp(e.second, p);
            // cycle detection
            if(x == y)
                return false;
            --cnt;
            p[x] = y;
        }
        // connected component check
        return cnt == 1;
    }

    int getp(int i, vector<int>& p)
    {
        while(i != p[i]) {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }
};
