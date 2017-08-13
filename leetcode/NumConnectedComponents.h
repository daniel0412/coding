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
        return dfsImpl(n, edges);
    }

  private:
    int dfsImpl(int n, const vector<pair<int, int> >& edges)
    {
        unordered_map<int, vector<int> > aj;
        for(const auto& e : edges) {
            aj[e.first].push_back(e.second);
        }
        vector<int> visited(n, 0);
        for(const auto& kv : aj) {
            if(visited[kv.first] == 0) {
                int num = 0;
                dfs(aj, kv.first, num, visited);
                n = n - num + 1;
            }
        }
        return n;
    }

    void dfs(unordered_map<int, vector<int> >& aj,
             int start,
             int& num,
             vector<int>& visited)
    {
        if(visited[start] > 0)
            return;
        visited[start] = 1;
        for(auto v : aj[start]) {
            ++num;
            if(aj.count(v)) {
                dfs(aj, v, num, visited);
            }
        }
        visited[start] = 2;
    }

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
            parents[i] = findParent(parents, parents[i]);
        }
        return parents[i];
    }
};
