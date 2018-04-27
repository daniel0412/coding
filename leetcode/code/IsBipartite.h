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

class IsBipartite {
  public:
    bool isBipartite(vector<vector<int> >& graph)
    {
        // since bipartite
        // only use 1/-1 to differentiate two groups of nodes
        vector<int> group(graph.size(), 0);
        for(int i = 0; i < graph.size(); ++i) {
            // if processed, continue
            if(group[i])
                continue;
            // if not processed
            // assign a randome group
            queue<int> q;
            q.push(i);
            group[i] = 1;
            while(!q.empty()) {
                int n = q.front();
                q.pop();
                // all linked nodes need to be assigned to the opposite group
                int curGroup = -group[n];
                for(auto d : graph[n]) {
                    // if not assigned, assign to opposite group, and push to
                    // queue to process its linked nodes
                    if(group[d] == 0) {
                        q.push(d);
                        group[d] = curGroup;
                    }
                    // if assigned, but was previoulsy assigned to a different
                    // group, indicating it is not bipartite
                    else if(group[d] != curGroup) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

  private:
};
