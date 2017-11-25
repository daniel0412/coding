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
        if(node == nullptr)
            return nullptr;
        unordered_map<int, UndirectedGraphNode*> m;
        m[node->label] = new UndirectedGraphNode(node->label);
        dfs(node, m);
        return m[node->label];
    }

  private:
    void dfs(UndirectedGraphNode* node,
             unordered_map<int, UndirectedGraphNode*>& m)
    {
        for(const auto ptr : node->neighbors) {
            if(m.find(ptr->label) == m.end()) {
                m[ptr->label] = new UndirectedGraphNode(ptr->label);
                m[node->label]->neighbors.emplace_back(m[ptr->label]);
                dfs(ptr, m);
            }
            else {
                m[node->label]->neighbors.emplace_back(m[ptr->label]);
            }
        }
    }

    void bfs(UndirectedGraphNode* node)
    {
        if(node == nullptr)
            return node;
        unordered_map<int, UndirectedGraphNode*> m;
        unordered_set<int> v;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        m[node->label] = new UndirectedGraphNode(node->label);
        while(!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            // this check is to remove double link between two nodes
            if(v.count(cur->label))
                continue;
            v.insert(cur->label);
            for(const auto ptr : cur->neighbors) {
                if(m.find(ptr->label) == m.end()) {
                    m[ptr->label] = new UndirectedGraphNode(ptr->label);
                }
                m[cur->label]->neighbors.push_back(m[ptr->label]);
                if(v.count(ptr->label) == 0)
                    q.push(ptr);
            }
        }
        return m[node->label];
    }
};
