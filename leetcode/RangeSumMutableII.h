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

class RangeSumMutableII {
  public:
    NumMatrix(vector<vector<int> >& matrix)
    {
        int m = matrix.size(), n = matrix.size();
        d_mat.resize(m, vector<int>(n, 0));
        d_tree.resize(m + 1, vector<int>(n + 1, 0));

        int nextI = 0, nextJ = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                d_mat[i - 1][j - 1] = matrix[i - 1][j - 1];
                d_tree[i][j] += matrix[i - 1][j - 1];
                nextI = i + (i & (i ^ (i - 1)));
                nextj = j + (j & (j ^ (j - 1)));
                if(nextI <= m) {
                    d_tree[nextI][j] += d_tree[i][j];
                }

                if(nextJ <= n) {
                    d_tree[i][nextJ] += d_tree[i][j];
                }

                if(nextI <= m && nextJ <= n) {
                    d_tree[nextI][nextJ] += d_tree[i][j];
                }
            }
        }
    }
    void update(int row, int col, int val)
    {
        int diff = val - d_mat[row][col];
        d_max[row][col] = val;
        ++row;
        ++col;
        for(int i = row; i < d_tree.size();) {
            for(int j = col; j < d_tree[0].size();) {
                d_tree[i][j] += diff;
                j += (j & (j ^ (j - 1)));
            }
            i += (i & (i ^ (i - 1)));
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return getSum(row2, col2) - getSum(row2, col1 - 1) -
            getSum(row1 - 1, col2) + getSum(row1 - 1, col1 - 1);
    }
    int getSum(int row, int col)
    {
        int sum = 0;
        ++row;
        ++col;
        int i = row, j = col;
        while(i > 0) {
            while(j > 0) {
                sum += d_tree[i][j];
                j -= (j & (j ^ (j - 1)));
            }
            i -= (i & (i ^ (i - 1)));
        }
        return sum;
    }

  private:
    vector<vector<int> > d_mat;
    vector<vector<int> > d_tree;
};
