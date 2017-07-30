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

class MaxRectangle {
  public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> hist(m, vector<int>(n,0));
        int nums = 0;
        for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                cnt = matrix[i][j]=='1' ? cnt+1 : 0;
                hist[i][j] = cnt;
                if(cnt) {
                    nums = max(nums, cnt);
                    int width = cnt, height = 0;
                    for(int k = i; k>=0; --k) {
                        if(hist[k][j]==0) break;
                        ++height;
                        width = min(width, hist[k][j]);
                        nums = max(nums, width*height);
                    }
                }
            }
        }
        return nums;
    }

  private:
};
