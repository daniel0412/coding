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

class MazeIII {
  public:
    int getLoc(int ncols, int x, int y) { return x * ncols + y; }

    string hasPath(vector<vector<int> >& maze,
                   vector<int>& start,
                   vector<int>& hole)
    {
        if(maze.empty() || maze[0].empty())
            return "impossible";
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        string dirStr = "durl";
        // cache transformed loc -> (steps, move ops)
        unordered_map<int, pair<int, string> > cache;
        cache[getLoc(maze[0].size(), start[0], start[1])] = {0, ""};
        return dfs(
            maze, start[0], start[1], hole[0], hole[1], cache, dirStr, dirs);
    }

  private:
    string dfs(vector<vector<int> >& m,
               int srcx,
               int srcy,
               int dstx,
               int dsty,
               unordered_map<int, pair<int, string> >& cache,
               const string& dirStr,
               const vector<pair<int, int> >& dirs)
    {
        int ncols = m[0].size();
        int srcLoc = getLoc(ncols, srcx, srcy);
        int dstLoc = getLoc(ncols, dstx, dsty);

        for(size_t i = 0; i < dirs.size(); ++i) {
            const auto& d = dirs[i];
            int nextx = srcx, nexty = srcy;
            int steps = cache[srcLoc].first;
            string path = cache[srcLoc].second;
            path.push_back(dirStr[i]);
            bool foundHole = false;
            while(nextx >= 0 && nexty >= 0 && nextx < m.size() &&
                  nexty < m[0].size() && m[nextx][nexty] != 1) {
                if(nextx == dstx && nexty == dsty) {
                    foundHole = true;
                    break;
                }
                nextx += d.first;
                nexty += d.second;
                ++steps;
            }

            if(foundHole) {
                if(cache.count(dstLoc) == 0 || steps < cache[dstLoc].first) {
                    cache[dstLoc].first = steps;
                    cache[dstLoc].second = path;
                }
                // hole found, then no need to continue recursive call
                continue;
            }
            else {
                nextx -= d.first;
                nexty -= d.second;
                --steps;

                int nextLoc = getLoc(ncols, nextx, nexty);
                if(cache.count(nextLoc) == 0 || steps < cache[nextLoc].first) {
                    cache[nextLoc].first = steps;
                    cache[nextLoc].second = path;
                    // continue recursive call
                    dfs(m, nextx, nexty, dstx, dsty, cache, dirStr, dirs);
                }
            }
        }
        return cache.count(dstLoc) ? cache[dstLoc].second : "impossible";
    }

  private:
};
