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
        int res = n;
        vector<int> roots(n);
        for(int i = 0; i < n; ++i)
            roots[i] = i;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(M[i][j]) {
                    int rooti = findRoot(i);
                    int rootj = findRoot(j);
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
        if(roots[i] != i) {
            roots[i] = findRoot(roots, roots[i]);
        }
        return roots[i];
    }
};
