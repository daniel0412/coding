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
        // initialize each user as its own union
        // so there are n individual unions initially
        int res = n;
        vector<int> roots(n);
        for(int i = 0; i < n; ++i)
            roots[i] = i;

        // loop over all friendship information, and merge union if two people are friends
        // since friendship is bidirectional, only need to loop the upper triangle of the square
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                // merge when i and j are friends
                if(M[i][j]) {
                    // find the root union i and j belongs to
                    int rooti = findRoot(roots, i);
                    int rootj = findRoot(roots, j);
                    // if currently they belong to different region, merge the root union
                    // and decrese the number of unions
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
    int findRoot(vector<int>& roots, int i)
    {
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
