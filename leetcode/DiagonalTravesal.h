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

class DiagonalTravesal {
  public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix)
    {
        vector<int> res;
        if(matrix.empty())
            return res;
        if(matrix.size() == 1)
            return matrix[0];
        bool upright = false, downleft = true;
        int nrows = matrix.size(), ncols = matrix[0].size();
        int row = -1, col = 0;  // initialization to fit in the following loop
        while(upright || downleft) {
            while(upright) {
                if(valid(nrows, ncols, row - 1, col + 1)) {
                    --row;
                    ++col;
                    res.push_back(matrix[row][col]);
                }
                else {
                    upright = false;
                    if(valid(nrows, ncols, row, col + 1)) {
                        ++col;
                        downleft = true;
                        res.push_back(matrix[row][col]);
                    }
                    else if(valid(nrows, ncols, row + 1, col)) {
                        ++row;
                        downleft = true;
                        res.push_back(matrix[row][col]);
                    }
                }
            }
            while(downleft) {
                if(valid(nrows, ncols, row + 1, col - 1)) {
                    ++row;
                    --col;
                    res.push_back(matrix[row][col]);
                }
                else {
                    downleft = false;
                    if(valid(nrows, ncols, row + 1, col)) {
                        ++row;
                        upright = true;
                        res.push_back(matrix[row][col]);
                    }
                    else if(valid(nrows, nocols, row, col + 1)) {
                        ++col;
                        upright = true;
                        res.push_back(matrix[row][col]);
                    }
                }
            }
        }
        return res;
    }

  private:
    bool valid(const int nrows, const int ncols, const int row, const int col)
    {
        return (row >= 0 && row < nrows && col >= 0 && col < ncols);
    }

    vector<int> fasterImpl(vector<vector<int> >& matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return vector<int>();
        int nrows = matrix.size(), ncols = matrix[0].size();
        vector<int> res(nrows * ncols);
        vector<pair<int, int> > dirs = {pair<int, int>{-1, 1},
                                        pair<int, int>{1, -1}};
        int r = 0, c = 0, k = 0;
        for(int i = 0; i < nrows * ncols; ++i) {
            res[i] = matrix[r][c];
            r += dirs[k].first;
            c += dirs[k].second;

            if(r >= nrows) {
                c += 2;
                --r;
                k = 1 - k;
            }
            if(c >= ncols) {
                --c;
                r += 2;
                k = 1 - k;
            }
            if(r < 0) {
                ++r;
                k = 1 - k;
            }
            if(c < 0) {
                ++c;
                k = 1 - k;
            }
        }
        return res;
    }
};
