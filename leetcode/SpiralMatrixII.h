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

class SpiralMatrixII {
  public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        // keep track of right/down we can go
        int right = n - 1, down = n - 1;
        // start from 0, keep increasing
        int val = 0;
        // since it is square, if odd, only one element in the center needs to be addressed
        int nRows = n / 2;
        // remember to update right/down as well
        for(int i = 0; i < nRows; ++i, --right, --down) {
            // up row
            for(int col = i; col <= right; ++col) {
                matrix[i][col] = ++val;
            }
            // right col
            for(int row = i + 1; row <= down; ++row) {
                matrix[row][right] = ++val;
            }
            // down row
            for(int col = right - 1; col >= i; --col) {
                matrix[down][col] = ++val;
            }
            // left col
            for(int row = down - 1; row > i; --row) {
                matrix[row][i] = ++val;
            }
        }
        // center element
        if(n % 2) {
            matrix[nRows][nRows] = ++val;
        }
        return matrix;
    }
private:
}
;
