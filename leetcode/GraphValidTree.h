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
    // second time implementation
    bool dfs(int n, vector<pair<int, int> >& edges)
    {
        vector<bool> v(n, false);
        unordered_map<int, vector<int> > m;
        // add for both directions
        for(const auto& e : edges) {
            m[e.first] = e.second;
            m[e.second] = e.first;
        }
        // check cycle
        if(!dfs_core(0, v, m, -1))
            return false;

        // check only one component
        for(auto vi : v) {
            if(!vi)
                return false;
        }
        return true;
    }

    bool dfs_core(int i,
             vector<bool>& v,
             unordered_map<int, vector<int> >& m,
             int pre)
    {
        // use pre to break parent/child cycle
        if(i == pre)
            return true;
        if(v[i])
            return false;
        for(auto id : m[i]) {
            v[id] = true;
            if(!dfs_core(id, v, m i))
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
        // start from a random node
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int id = q.front();
            q.pop();
            v.insert(id);
            for(auto i : g[id]) {
                // check cycle
                if(v.count(i))
                    return false;
                q.push(i);
                // from id, we accessed i, so remove id from i to break parent-child cycle
                g[i].erase(id);
            }
        }
        // check only one component
        return v.size() == n;
    }

    // union find
    bool unionfind(int n, vector<pair<int, int> >& edges)
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
