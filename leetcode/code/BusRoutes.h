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

class BusRoutes {
  public:
    int numBusesToDestination(vector<vector<int> >& routes, int S, int T)
    {
        if(S == T)
            return 0;
        unordered_map<int, unordered_set<int> > m;
        for(size_t i = 0; i < routes.size(); ++i) {
            for(size_t j = 0; j < routes[i].size(); ++j) {
                m[routes[i][j]].insert(i);
            }
        }
        queue<int> q;
        unordered_set<int> v;
        int cnt = 0;
        q.push(S);
        v.insert(S);

        while(!q.empty()) {
            ++cnt;
            int qsize = q.size();
            for(size_t i = 0; i < qsize; ++i) {
                int cur = q.front();
                q.pop();
                for(auto r : m[cur]) {
                    for(auto stop : routes[r]) {
                        if(stop == T)
                            return cnt;
                        if(v.count(stop) == 0) {
                            q.push(stop);
                            v.insert(stop);
                        }
                    }
                    routes[r].clear();
                }
            }
        }
        return -1;
    }

  private:
};
