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

class KthSmallestElementInMultiplicationTable {
  public:
    int findKthNumber(int m, int n, int k)
    {
        int left = 1, right = m * n;
        int mid = left + (right - left) / 2;
        int res = 0;

        // binary search of the value solution sapce
        while(left < right) {
            mid = left + (right - left) / 2;
            // find count <= mid
            int row = m, col = 1, cnt = 0;
            while(row > 0 && col <= n) {
                if(row * col <= mid) {
                    cnt += row;
                    ++col;
                }
                else {
                    --row;
                }
            }
            if(cnt < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }

  private:
};
