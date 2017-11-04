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
      int binarySearchImpl(const vector<vector<int>>& matrix, int k) {
          int n = matrix.size();
          int low = matrix[0][0], high = matrix[n-1][n-1];
          while(low < high) {
              int mid = low + (high-low)/2;
              if(numNoGreaterThanMidLessThanK(matrix, mid, k)) {
                  low = mid + 1;
              }else {
                  high = mid;
              }
          }
          return low;
      }

  private:
      bool numNoGreaterThanMidLessThanK(const vector<vector<int>>& matrix, const int val, const int k) {
          int n = matrix.size();
          int i = n-1, j = 0;
          int res = 0;
          while(i >= 0 && j < n) {
              if(matrix[i][j] > val) {
                  --i;
              }else {
                  res += i + 1;
                  if(res >= k) return false;
                  ++j;
              }
          }
          return true;
      }
};
