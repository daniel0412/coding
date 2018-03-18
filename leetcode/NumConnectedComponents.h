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

class NumConnectedComponents {
  public:
    int countComponents(int n, vector<pair<int, int> >& edges)
    {
        // return unionfindImpl(n, edges);
        return dfsImpl(n, edges);
    }

  private:
    int dfsImpl(int n, const vector<pair<int, int> >& edges) 
    {
        unordered_map<int, vector<int> > aj;
        // undirected graph, need to store both directions
        for(const auto& e : edges) {
            aj[e.first].push_back(e.second);
            aj[e.second].push_back(e.first);
        }
        vector<bool> v(n, false);
        int res = 0;
        for(int i = 0;  i < n; ++i) {
            if(!v[i]) {
                ++res;
                dfs(aj, v, i);
            }
        }
        return res;
    }

    void dfs(const unordered_map<int, vector<int>>& aj, vector<bool>& v, int i)
    {
        v[i] = true;
        for(auto j : aj[i]) {
            if(!v[j]) {
                dfs(aj, v, j);
            }
        }
    }

    // union find solution
    int unionfindImpl(int n, const vector<pair<int, int> >& edges)
    {
        vector<int> parents(n, 0);
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for(const auto& e : edges) {
            int parent1 = findParent(parents, e.first);
            int parent2 = findParent(parents, e.second);
            if(parent1 != parent2) {
                --n;
                parents[parent2] = parent1;
            }
        }
        return n;
    }

    int findParent(vector<int>& parents, int i)
    {
        while(parents[i] != i) {
            // path compression
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return parents[i];
    }
};
