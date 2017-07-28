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
    bool validTree(int n, vector<pair<int, int> >& edges) {
        return unionfind(n, edges);
        //return dfs(n, edges);
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
                graph[d].erase(c);
            }
        }
        return visited.size() == n;
    }
    bool unionfind(int n, const vector<pair<int, int> >& edges)
    {
        vector<int> roots(n, -1);
        for(const auto& p : edges) {
            int root1 = findRoot(roots, p.first);
            int root2 = findRoot(roots, p.second);
            if(root1 == root2)
                return false;
            roots[root1] = root2;
        }
        return true;
    }
    int findRoot(vector<int>& roots, int i)
    {
        while(roots[i] != -1)
            i = roots[i];
        return i;
    }
};
