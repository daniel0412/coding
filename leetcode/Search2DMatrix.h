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

class Search2DMatrix {
  public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int x = mid / n, y = mid % n;
            int val = matrix[x][y];
            if(val == target)
                return true;
            else if(val < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }

  private:
};
