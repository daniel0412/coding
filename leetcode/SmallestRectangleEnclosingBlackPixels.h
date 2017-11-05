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
    int binarysearch(const vector<vector<char> >& image,
                     const int x,
                     const int y)
    {
        int up = decreasingBinarySearchImpl(image, 0, x, true);
        int down =
            increasingBinarySearchImpl(image, x, image.size() - 1, true);
        int left = decreasingBinarySearchImpl(image, 0, y, false);
        int right =
            increasingBinarySearchImpl(image, y, image[0].size() - 1, false);
        return (right - left + 1) * (down - u + 1);
    }

    int increasingBinarySearchImpl(const vector<vector<char> >& image,
                                   int minB,
                                   int maxB,
                                   bool vertical)
    {
        while(minB < maxB) {
            int k = 0;
            int midB = minB + (maxB - minB) / 2;
            int boundary = vertical ? image.size() : image[0].size();
            while(k < boundary &&
                  (vertical ? image[midB][k] : image[k][midB]) != '1') {
                ++k;
            }
            if(k < boundary) {
                minB = midB;
            }
            else {
                maxB = midB - 1;
            }
        }
        return minB;
    }

    int decreasingBinarySearchImpl(const vector<vector<char> >& image,
                                   int minB,
                                   int maxB,
                                   bool vertical)
    {
        while(minB < maxB) {
            int k = 0;
            int midB = minB + (maxB - minB) / 2;
            int boundary = vertical ? image.size() : image[0].size();
            while(k < boundary &&
                  (vertical ? image[midB][k] : image[k][midB]) != '1') {
                ++k;
            }
            if(k < boundary) {
                maxB = midB;
            }
            else {
                minB = midB + 1;
            }
        }
        return maxB;
    }
};
