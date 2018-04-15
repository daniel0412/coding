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

class ShortestDistFromAllBuildings {
  public:
    int shortestDistance(vector<vector<int> >& grid)
    {
        int m = grid.size(), n = grid[0].size();
        // to denote visited or not, also indicate num of buildings
        int visitval = 0;
        int res = INT_MAX;
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int> > totalDist(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    queue<pair<int, int> > q;
                    q.push({i, j});
                    int level = 1;
                    res = INT_MAX;
                    while(!q.empty()) {
                        // use queue size to indicate if current level finishes
                        int size = q.size();
                        for(int k = 0; k < size; ++k) {
                            pair<int, int> p = q.front();
                            q.pop();
                            for(const auto& d : dirs) {
                                int curi = p.first + d.first,
                                    curj = p.second + d.second;
                                if(curi >= 0 && curj >= 0 && curi < m &&
                                   curj < n && grid[curi][curj] == visitVal) {
                                    --grid[curi][curj];  // indicate visited
                                                         // by x num of
                                                         // buildings
                                    totalDist[curi][curj] += level;
                                    res = min(res, level);  // notice that this
                                                            // is only updated
                                                            // when this pos is
                                                            // visited by all
                                                            // buildings
                                    q.push({curi, curj});
                                }
                            }
                        }
                        ++level;
                    }
                    --visitVal;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }


  private:
};
