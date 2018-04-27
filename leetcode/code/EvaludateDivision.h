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

class EvaludateDivision {
  public:
    vector<double> calcEquation(vector<pair<string, string> > equations,
                                vector<double>& values,
                                vector<pair<string, string> > queries)
    {
        // store all the results
        unordered_map<string, double> m;
        // store the graph
        unordered_map<string, unordered_set<string> > g;

        for(int i = 0; i < equations.size(); ++i) {
            const auto& p = equations[i];
            m[p.first + "/" + p.second] = values[i];
            g[p.first].insert(p.second);

            // screen out special case
            if(values[i] != 0) {
                m[p.second + "/" + p.first] = 1.0 / values[i];
                g[p.second].insert(p.first);
            }
        }

        vector<double> res(queries.size(), -1.0);
        for(int i = 0; i < queries.size(); ++i) {
            const auto& p = queries[i];
            // ATTENTION: even if start/end are the same, need to make sure they are inside the dictionary
            if(p.first == p.second && g.count(p.first)) {
                res[i] = 1.0;
            }
            else {
                bool found = false;
                unordered_set<string> v;
                res[i] = dfs(p.first, p.second, g, m, found, 1.0, v);
            }
        }
        return res;
    }

    double dfs(string s,
               string e,
               unordered_map<string, unordered_set<string> >& g,
               unordered_map<string, double>& m,
               bool& found,
               double r,
               unordered_set<string>& v)
    {
        for(auto& ss : g[s]) {
            if(ss == s || v.count(ss))
                continue;
            string exp = s + "/" + ss;
            if(ss == e) {
                found = true;
                return r * m[exp];
            }
            v.insert(s);
            double res = dfs(ss, e, g, m, found, r * m[exp], v);
            if(found)
                return res;
        }
        return -1.0;
    }

  private:
};
