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

class FriendCycle {
  public:
    int findCircleNum(vector<vector<int> >& M)
    {
        int n = M.size();
        // initially assume there are n friend cycles, i.e., each user form
        // his/her own cycle
        int res = n;
        // roots vector to indicate which friend cycle each user belongs to
        vector<int> roots(n);

        // initialize roots vector such that each user forms his/her own cycle
        for(size_t i = 0; i < n; ++i)
            roots[i] = i;

        // loop over all friendship information, and merge friend cycle if two
        // people are friends
        // since friendship is bidirectional, only need to loop the upper
        // triangle of the square
        for(size_t i = 0; i < n; ++i) {
            for(size_t j = i + 1; j < n; ++j) {
                // merge when i and j are friends
                if(M[i][j]) {
                    // find the friend cycle i and j belongs to respective
                    int rooti = findRoot(roots, i);
                    int rootj = findRoot(roots, j);
                    // if i and j do not fall into the same friend cycle, merge
                    // the two cycles
                    // at the same time, decrease the number of friend cycles
                    // by 1
                    if(rooti != rootj) {
                        --res;
                        roots[rooti] = rootj;
                    }
                }
            }
        }
        return res;
    }

  private:
    // findRoot function finds which friend cycle the given user belongs to
    int findRoot(vector<int>& roots, int i)
    {
        // trace which frined cycle i belongs to
        while(roots[i] != i) {
            roots[i] = roots[roots[i]];
            i = roots[i];
        }
        return roots[i];
    }


    // bfs solution
    int bfs(vector<vector<int> >& M)
    {
        int n = M.size();
        if(n <= 1)
            return n;
        queue<int> q;
        vector<bool> visited(n, false);
        int cnt = 0;

        for(int i = 0; i < n; ++i) {
            if(visited[i])
                continue;
            visited[i] = true;
            q.push(i);
            while(!q.empty()) {
                int id = q.front();
                q.pop();
                for(int j = 0; j < n; ++j) {
                    if(M[id][j] && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            ++cnt;
        }

        return cnt;
    }
};
