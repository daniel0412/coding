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
  private:
};
