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

class AlienDict {
  public:
    string alienOrder(vector<string>& words)
    {
        if(words.empty())
            return "";
        if(words.size() == 1)
            return words[0];
        unordered_map<char, vector<char> > graph;
        unordered_map<char, int> degrees;
        buildGraph(words, graph, degrees);
        queue<char> q;
        for(const auto& d : degrees) {
            if(d.second == 0) {
                q.push(d.first);
            }
        }
        string res;
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res.push_back(c);
            for(const auto cc : graph[c]) {
                if(--degrees[cc] == 0)
                    q.push(cc);
            }
        }
        return res;
    }

  private:
    void findEdge(const string& s1, const string& s2, pair<char, char>& edge)
    {
        size_t i = 0;
        while(i < s1.size() && i < s2.size()) {
            if(s1[i] != s2[i]) {
                edge.first = s1[i];
                edge.second = s2[i];
                return;
            }
            ++i;
        }
    }

    void buildGraph(const vector<string>& dict,
                    unordered_map<char, vector<char> >& graph,
                    unordered_map<char, int>& degrees)
    {
        for(size_t i = 0; i < dict.size() - 1; ++i) {
            pair<char, char> edge({0, 0});
            findEdge(dict[i], dict[i + 1], edge);
            if(edge.first != edge.second) {
                if(degrees.count(edge.first) == 0)
                    degrees[edge.first] = 0;
                if(degrees.count(edge.second) == 0)
                    degrees[edge.second] = 0;
                ++degrees[edge.second];
                graph[edge.first].push_back(edge.second);
            }
        }
    }
};
