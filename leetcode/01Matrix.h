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

class Matrix {
  public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return matrix;
        // dfs exceeding time limit
        // return dfswrapper(matrix);
        // bfs faster
        // return bfs(matrix);
        // two passes fastest
        return twopass(matrix);
    }

  private:
    vector<vector<int> > dfswrapper(vector<vector<int> >& matrix)
    {
        const int MAX_STEPS = matrix.size() + matrix[0].size();
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] = matrix[i][j] ? MAX_STEPS : 0;
            }
        }
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    dfs(matrix, i + 1, j, 1);
                    dfs(matrix, i - 1, j, 1);
                    dfs(matrix, i, j + 1, 1);
                    dfs(matrix, i, j - 1, 1);
                }
            }
        }
        return matrix;
    }
    void dfs(vector<vector<int> >& matrix, int i, int j, int steps)
    {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() ||
           matrix[i][j] <= steps)
            return;
        matrix[i][j] = steps;
        dfs(matrix, i + 1, j, steps + 1);
        dfs(matrix, i - 1, j, steps + 1);
        dfs(matrix, i, j + 1, steps + 1);
        dfs(matrix, i, j - 1, steps + 1);
    }

    vector<vector<int> > bfs(vector<vector<int> >& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int> > q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j]) {
                    matrix[i][j] = INT_MAX;
                }
                else {
                    q.emplace(pair<int, int>({i, j}));
                }
            }
        }
        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            for(const auto& d : dirs) {
                int row = c.first + d.first;
                int col = c.second + d.second;
                int steps = matrix[c.first][c.second] + 1;
                if(row < 0 || col < 0 || row >= m || col >= n ||
                   matrix[row][col] <= steps)
                    continue;
                matrix[row][col] = steps;
                q.emplace(pair<int, int>({row, col}));
            }
        }
        return matrix;
    }

    vector<vector<int> > twopass(vector<vector<int> >& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > res(m, vector<int>(n, INT_MAX - 1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    res[i][j] = 0;
                }
                else {
                    if(i > 0)
                        res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                    if(j > 0)
                        res[i][j] = min(res[i][j], res[i][j - 1] + 1);
                }
            }
        }
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(matrix[i][j]) {
                    if(i < m - 1) {
                        res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                    }
                    if(j < n - 1) {
                        res[i][j] = min(res[i][j], res[i][j + 1] + 1);
                    }
                }
            }
        }
        return res;
    }
};
