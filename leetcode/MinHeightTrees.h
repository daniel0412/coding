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

class MinHeightTrees {
  public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges)
    {
        return degreeImpl(n, edges);
    }

    // degree implememtation
    // check the stopping criteria
    vector<int> degreeImpl(int n, vector<pair<int, int> >& edges)
    {
        if(n == 1)
            return vector<int>{0};
        unordered_map<int, unordered_set<int> > m;
        for(const auto& e : edges) {
            m[e.first].insert(e.second);
            m[e.second].insert(e.first);
        }
        queue<int> q;
        for(const auto& p : m) {
            if(p.second.size() == 1) {
                q.push(p.first);
            }
        }
        // stoping criteria
        while(n > 2) {
            int size = q.size();
            n -= size;
            for(int k = 0; k < size; ++k) {
                int t = q.front();
                q.pop();
                for(auto i : m[t]) {
                    // break parent/child cycle
                    m[i].erase(t);
                    if(m[i].size() == 1)
                        q.push(i);
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
    // brute force, timeout
    vector<int> bfTLEImpl(int n, vector<pair<int, int> >& edges)
    {
        unordered_map<int, vector<int> > m;
        for(const auto& e : edges) {
            m[e.first].push_back(e.second);
            m[e.second].push_back(e.first);
        }
        vector<int> res;
        int minH = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int h = getHeight(i, n, m, minH);
            if(h < minH) {
                minH = h;
                res.clear();
                res.push_back(i);
            }
            else if(h == minH) {
                res.push_back(i);
            }
        }
        return res;
    }


  private:
    int getHeight(const int root,
                  const int n,
                  const unordered_map<int, vector<int> >& m,
                  const int minH)
    {
        queue<int> q;
        q.push(root);
        const int SEP = -1;
        q.push(SEP);
        vector<bool> visited(n, false);
        visited[root] = true;
        int h = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == SEP) {
                if(q.empty())
                    break;
                else
                    q.push(SEP);

                ++h;
                if(h > minH)
                    return h;
                continue;
            }
            for(auto t : m[node]) {
                if(!visited[t]) {
                    visited[t] = true;
                    q.push(t);
                }
            }
        }
        return h;
    }
};
