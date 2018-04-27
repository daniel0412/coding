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

class AllPathFromSrcToTarget {
  public:
    using vv = vector<vector<int> >;
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph)
    {
        vector<vector<int> > res;
        if(graph.empty() || graph[0].empty())
            return res;
        vector<int> path;
        dfs(graph, res, path, 0);
        return res;
    }

    void dfs(const vv& g, vv& res, vector<int>& path, int i)
    {
        path.push_back(i);
        if(i == g.size() - 1) {
            res.emplace_back(path);
        }
        else {
            for(auto next : g[i]) {
                dfs(g, res, path, next);
            }
        }
        path.pop_back();
    }

    // only visit one node once
    vv dfsWithCache(const vv& g, unordered_map<int, vv>& cache, int i)
    {
        if(cache.count(i))
            return cache[i];
        vv res;
        if(i == g.size() - 1) {
            vector<int> path = {i};
            res.emplace_back(path);
        }
        else {
            for(auto next : g[i]) {
                vv subpaths = dfsWithCache(g, cache, next);
                for(auto& p : subpaths) {
                    p.insert(p.begin(), i);
                    res.emplace_back(p);
                }
            }
        }
        cache[i] = res;
        return res;
    }

  private:
};
