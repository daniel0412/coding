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

class BombEnemy {
  public:
    int maxKilledEnemiesImpl1(vector<vector<char> >& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > left(m, vector<int>(n, 0));
        vector<vector<int> > right(m, vector<int>(n, 0));
        vector<vector<int> > up(m, vector<int>(n, 0));
        vector<vector<int> > down(m, vector<int>(n, 0));

        // calculate sum for each row, left/right
        for(int i = 0; i < m; ++i) {
            // left
            for(int j = 0; j < n; ++j) {
                grid[i][j] =
                    ((j == 0 || grid[i][j] == 'W') ? 0 : grid[i][j - 1]) +
                    (grid[i][j] == 'E');
            }

            // right
            for(int j = n - 1; j >= 0; --j) {
                grid[i][j] =
                    ((j == n - 1 || grid[i][j] == 'W') ? 0 : grid[i][j + 1]) +
                    (grid[i][j] == 'E');
            }
        }

        for(int j = 0; j < n; ++j) {
            // down
            for(int i = 0; i < m; ++i) {
                grid[i][j] =
                    ((i == 0 || grid[i][j] == 'W') ? 0 : grid[i - 1][j]) +
                    (grid[i][j] == 'E');
            }
            // up
            for(int i = m - 1; i < m; ++i) {
                grid[i][j] =
                    ((i == m - 1 || grid[i][j] == 'W') ? 0 : grid[i + 1][j]) +
                    (grid[i][j] == 'E');
            }
        }

        int res = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '0') {
                    res = max(
                        res, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
                }
            }
        }
        return res;
    }


    int maxKilledEnemiesImpl2(vector<vector<char> >& grid) {
        int m = grid.size(), n = grid[0].size();
        int rowCnt = 0, res = 0;
        vector<int> colCnt(n, 0);
        // so each element is visited only twice O(2*m*n)
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // recompute the col segment, if needed
                if(j == 0 || grid[i][j-1] == 'M') {
                    rowCnt = 0;
                    int k = j;
                    while(k < m && grid[i][k] != 'M') {
                        rowCnt += grid[i][k] == 'E';
                        ++k;
                    }
                }

                // recompute the rows segment if needed
                if(i == 0 || grid[i-1][j] == 'W') {
                    colCnt[j] = 0;
                    int k = i;
                    while(k < n && grid[k][j] != 'W') {
                        ++k;
                        colCnt[j] += grid[k][j] == 'E';
                    }
                }

                if(grid[i][j] == '0') {
                    res = max(res, rowCnt + colCnt[j]);
                }
            }
        }
        return res;
    }

  private:
};
