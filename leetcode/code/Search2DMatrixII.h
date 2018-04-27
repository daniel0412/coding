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

class Search2DMatrixII {
  public:
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
          if(matrix.empty() || matrix[0].empty()) return false;
          int m = matrix.size(), n = matrix[0].size();
          int row = m - 1, col = 0;
          // only need to check single sided boundary
          while(row >= 0 && col < n) {
              if(matrix[row][col] == target) return true;
              else if(matrix[row][col] < target) {
                  ++col;
              }else {
                  --row;
              }
          }
          return false;
      }
  private:
};
