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

class SmallestRectangleEnclosingBlackPixels {
  public:
    int minArea(vector<vector<char> >& image, int x, int y) {}

  private:
    // brute force to find boundaries
    int bruteforce(const vector<vector<char> >& image,
                   const int x,
                   const int y)
    {
        int m = image.size(), n = image[0].size();
        int up = x, down = x;
        int left = y, right = y;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(image[i][j] == '1') {
                    up = min(up, i);
                    down = max(down, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        return (up - down + 1) * (right - left + 1);
    }

    // binary search to find boundaries
    int minAreaImpl(const vector<vector<char> >& image, int x, int y)
    {
        int nrows = image.size(), ncols = image[0].size();
        int up = binarysearchimpl(image, 0, x, 0, ncols - 1, false, true);
        int down = binarysearchimpl(image, x, nrows - 1, true, true);
        int left = binarysearchimpl(image, 0, y, up, down, false, false);
        int right =
            binarysearchimpl(image, y, ncols - 1, up, down, true, false);
        return (right - left + 1) * (down - up + 1);
    }


    int binarysearchimpl(const vector<vector<char> >& image,
                         int start,
                         int end,
                         int low,
                         int high,
                         bool inc,
                         bool vdir)
    {
        int k = low;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            while(k <= high &&
                  (vdir ? image[mid][k] == '0' : image[k][mid] == '0')) {
                ++k;
            }
            if(k > high) {  // not found
                if(inc) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {  // found
                if(inc) {
                    start = mid;
                }
                else {
                    end = mid;
                }
            }
        }
        return inc ? start : end;
    }
};
