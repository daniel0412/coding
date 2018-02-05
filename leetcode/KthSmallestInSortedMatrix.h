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

class KthSmallestInSortedMatrix {
  public:
      // heap solution, but need O(n^2*log(k))
      int kthSmallest(vector<vector<int>>& matrix, int k) {
          priority_queue<int, vector<int>, std::lesser<int>()> q;
          int m = matrix.size(), n = matrix[0].size();
          for(int i = 0; i < m; ++i) {
              for(int j = 0; j < n; ++j) {
                  if(q.size() < k) {
                      q.emplace(matrix[i][j]);
                  }else {
                      if(matrix[i][j] < q.top()) {
                          q.pop();
                          q.emplace(matrix[i][j]);
                      }else {
                          continue;
                      }
                  }
              }
          }
          return q.top();
      }

      // binary search solution, time complexity O(2*n*log(max-min))

      using vv = vector<vector<int> >;
      int kthSmallest(vector<vector<int> >& matrix, int k)
      {
          int s = matrix[0][0], e = matrix.back().back();
          while(s < e) {
              int m = s + (e - s) / 2;
              int cnt = countLessAndEqual(matrix, k, m);
              if(cnt < k) {
                  s = m + 1;
              }
              else {
                  e = m;
              }
          }
          return e;
      }

      int countLessAndEqual(const vv& matrix, int k, int val)
      {
          int nRows = matrix.size(), nCols = matrix[0].size();
          int row = nRows - 1, col = 0;
          int cnt = 0;
          while(row >= 0 && col < nCols) {
              if(matrix[row][col] <= val) {
                  cnt += (row + 1);
                  ++col;
              }
              else {
                  --row;
              }
          }
          return cnt;
      }
};
