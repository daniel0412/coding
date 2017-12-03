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

class LongestLineOfConsecutiveOnesInMatrix {
  public:
    int longestLine(vector<vector<int> >& M)
    {
        if(M.empty() || M[0].empty())
            return 0;
    }

  private:
    int dpImpl(const vector<vector<int> >& M)
    {
        int m = M.size(), n = M[0].size();
        vector<vector<vector<int> > > dp(
            m, vector<vector<int> >(n, vector<int>(4, 0)));
        int maxLen = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(M[i][j] == 0)
                    continue;
                for(int k = 0; k < 4; ++k)
                    dp[i][j][k] = 1;
                // horizontal
                if(j > 0)
                    dp[i][j][0] += dp[i][j - 1][0];
                // vertical
                if(i > 0)
                    dp[i][j][1] += dp[i - 1][j][1];
                // diagonal
                if(i > 0 && j > 0)
                    dp[i][j][2] += dp[i - 1][j - 1][2];
                // anti-diagonal
                if(i > 0 && j < n - 1)
                    dp[i][j][3] += dp[i - 1][j + 1][3];
                maxLen = max(maxLen, max(dp[i][j][0], dp[i][j][1]));
                maxLen = max(maxLen, max(dp[i][j][3], dp[i][j][4]));
            }
        }
        return maxLen;
    }

    int dfsImpl(const vector<vector<int> >& M)
    {
        int m = M.size(), n = M[0].size();
        int maxLen = 0;
        vector<vector<int> > dirs = {{0, 1}, {1, 0}, {1, 1}, {-1, -1}};

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(M[i][j] == 0)
                    continue;
                for(int k = 0; k < dirs.size(); ++k) {
                    int cnt = 0;
                    int x = i, y = j;
                    while(x >= 0 && x < m && y >= 0 && y < n && M[x][y]) {
                        ++cnt;
                        x += dirs[k][0];
                        y += dirs[k][1];
                    }
                    maxLen = max(maxLen, cnt);
                }
            }
        }
        return maxLen;
    }
};
