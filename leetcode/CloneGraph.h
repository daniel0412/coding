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

class CloneGraph {
  public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
    {
        // corner case, exclude
        if(node == nullptr)
            return nullptr;

        return bfs(node);

        // unordered_map<int, UndirectedGraphNode*> m;
        // return dfs(m, node);
    }

  private:
    UndirectedGraphNode* dfs(unordered_map<int, UndirectedGraphNode*>& m,
                             UndirectedGraphNode* cur)
    {
        // termination criteria
        if(m.count(cur->label)) {
            return m[cur->label];
        }

        // not found in map, create new node
        m[cur->label] = new UndirectedGraphNode(cur->label);

        // construct all neighbors
        for(auto& n : cur->neighbors) {
            // recursively construct children nodes
            m[cur->label]->neighbors.push_back(dfs(m, n));
        }
        return m[cur->label];
    }

    UndirectedGraphNode* bfs(UndirectedGraphNode* node)
    {
        // queue to store the current level
        queue<UndirectedGraphNode*> q;
        q.push(node);
        // store the label->new node mapping
        unordered_map<int, UndirectedGraphNode*> m;
        m[node->label] = new UndirectedGraphNode(node->label);

        // store all the processed nodes to de-duplicate
        unordered_set<int> v;
        v.insert(node->label);

        while(!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            for(const auto& ptr : cur->neighbors) {
                // create new node when not found in the map
                if(m.find(ptr->label) == m.end()) {
                    m[ptr->label] = new UndirectedGraphNode(ptr->label);
                }
                // construct the neighbors
                m[cur->label]->neighbors.push_back(m[ptr->label]);
                // build up the queue only when not processed before
                if(v.count(ptr->label) == 0) {
                    q.push(ptr);
                    v.insert(ptr->label);
                }
            }
        }
        return m[node->label];
    }
};
