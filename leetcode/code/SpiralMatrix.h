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

class SpiralMatrix {
  public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())
            return res;
        int m = matrix.size(), n = matrix[0].size();
        // keep track of rightmost and downest col and row
        int p = m - 1, q = n - 1;
        // boundary
        int nRows = m > n ? (n + 1) / 2 : (m + 1) / 2;
        for(int i = 0; i < nRows; ++i, --p, --q) {
            // up left->right
            for(int col = i; col <= q; ++col) {
                res.push_back(matrix[i][col]);
            }
            // right up->down
            for(int row = i + 1; row <= p; ++row) {
                res.push_back(matrix[row][q]);
            }
            // last single line finished
            if(i == p || i == q)
                break;
            //down right->left
            for(int col = q - 1; col >= i; --col) {
                res.push_back(matrix[p][col]);
            }
            //left down->up
            for(int row = p - 1; row > i; --row) {
                res.push_back(matrix[row][i]);
            }
        }
        return res;
    }

  private:
};
