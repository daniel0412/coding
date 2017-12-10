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

class RedundantConnection {
  public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {}

  private:
    vector<int> unionFindImpl(vector<vector<int> >& edges)
    {
        int n = 0;
        for(const auto& e : edges) {
            n = max(n, e[1]);
        }
        vector<int> root(n + 1, 0);
        for(int i = 0; i <= n; ++i) root[i] = i;
        for(const auto& e : edges) {
            int r1 = findRoot(e[0]), r2 = findRoot(e[1]);
            if(r1 == r2)
                return e;
            root[r2] = root[r1];
        }
        return {};
    }

    int findRoot(int i, vector<int>& root)
    {
        while(root[i] != i) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return root[i];
    }
};
