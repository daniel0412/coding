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

class SparseMatrixMultiplication {
  public:
      vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
          int m = A.size(), n = A[0].size(), q = B[0].size();

          vector<vector<int>> res(m, vector<int>(q, 0));
          for(int i = 0; i < m; ++i) {
              for(int j = 0; j < n; ++j) {
                  if(A[i][j])
                      for(int k = 0; k < q; ++k) {
                          if(B[k][j]) res[i][k] += A[i][j] * B[j][k];
                      }
                  }
              }
          return res;
          }
  private:
};
