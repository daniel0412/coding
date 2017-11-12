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

class NumOfIslandII {
  public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int> >& positions)
    {
        vector<int> res;
        if(m <= 0 || n <= 0)
            return res;
        // initially all water, thus no roots, default as -1
        vector<int> roots(m * n, -1);
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int nums = 0;
        for(const auto& p : positions) {
            ++nums;
            int id = p.first * n + p.second;
            // before union, mark root as itself, to distinguish it from water -1
            roots[id] = id;
            // for each sourronding position, if belong to diff islands, unite
            for(const auto& d : dirs) {
                int x = p.first + d.first, y = p.second + d.second;
                int curId = x * n + y;
                if(x < 0 || y < 0 || x >= m || y >= n || roots[curId] == -1)
                    continue;
                int newRoot = findRoot(roots, curId);
                if(id != newRoot) {
                    --nums;
                    roots[id] = newRoot;
                    // update to keep track of the parent
                    id = newRoot;
                }
            }
            res.push_back(nums);
        }
        return res;
    }

  private:
    int findRoot(vector<int>& roots, int id)
    {
        while(id != roots[id]) {
            // path compression
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
};
