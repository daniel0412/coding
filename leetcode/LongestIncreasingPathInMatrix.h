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

class LongestIncreasingPathInMatrix {
  public:
    int longestIncreasingPath(vector<vector<int> >& matrix)
    {
        return dfs(matrix);
    }
    int dfs(vector<vector<int> >& matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int> > lmatrix(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int tmpLen = dfsImpl(i, j, m, n, matrix, lmatrix);
		maxLen = max(maxLen, tmpLen);
            }
        }
        return maxLen;
    }

  private:
    int dfsImpl(const int i,
                const int j,
                const int m,
                const int n,
                const vector<vector<int> >& matrix,
                vector<vector<int> >& lmatrix)
    {
        if(lmatrix[i][j])
            return lmatrix[i][j];
        int leftLen =
            (valid(i, j - 1, m, n) && matrix[i][j] < matrix[i][j - 1]) ?
            dfsImpl(i, j - 1, m, n, matrix, lmatrix) :
            0;
        int rightLen =
            (valid(i, j + 1, m, n) && matrix[i][j] < matrix[i][j + 1]) ?
            dfsImpl(i, j + 1, m, n, matrix, lmatrix) :
            0;
        int upLen =
            (valid(i - 1, j, m, n) && matrix[i][j] < matrix[i - 1][j]) ?
            dfsImpl(i - 1, j, m, n, matrix, lmatrix) :
            0;
        int downLen =
            (valid(i + 1, j, m, n) && matrix[i][j] < matrix[i + 1][j]) ?
            dfsImpl(i + 1, j, m, n, matrix, lmatrix) :
            0;
        lmatrix[i][j] = 1 + max(max(leftLen, rightLen), max(upLen, downLen));
        return lmatrix[i][j];
    }
    bool validIndex(const int i, const int j, const int m, const int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};
