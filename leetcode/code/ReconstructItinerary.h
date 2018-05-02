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

class ReconstructItinerary {
  public:
    vector<string> findItinerary(vector<pair<string, string> > tickets)
    {
        unordered_map<string, multiset<string> > m;
        for(const auto& p : tickets) {
            m[p.first].insert(p.second);
        }

        vector<string> res;
        dfs(m, "JFK", res);
        return {res.rbegin(), res.rend()};
    }

    void dfs(unordered_map<string, multiset<string> >& m,
             string start,
             vector<string>& res)
    {
        while(!m[start].empty()) {
            auto iter = m[start].begin();
            string next = *iter;
            m[start].erase(iter);
            dfs(m, next, res);
        }
        res.emplace_back(start);
    }

  private:
};
