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
    // find width/height solution
    int maximalRectangle(vector<vector<char> >& matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size(), n = matrix[0].size();
        // keep track of ith row, from left to right, width of 1s up to jth col
        vector<vector<int> > hist(m, vector<int>(n, 0));
        int nums = 0;
        for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                // get ith row, from jth col to left, how many consecutives 1s
                cnt = matrix[i][j] == '1' ? cnt + 1 : 0;
                hist[i][j] = cnt;
                if(cnt) {
                    nums = max(nums, cnt);
                    int width = cnt, height = 0;
                    // from ith row, go back and modify height and width
                    for(int k = i; k >= 0; --k) {
                        if(hist[k][j] == 0)
                            break;
                        ++height;
                        width = min(width, hist[k][j]);
                        nums = max(nums, width * height);
                    }
                }
            }
        }
        return nums;
    }


    // Largest rectangle in histogram solution

    int maximalRectangle(vector<vector<char> >& matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        // sotres the histogram up to the ith row
        vector<int> heights(n, 0);
        int res = 0;
        for(int i = 0; i < m; ++i) {
            // resize since the subproblem increased its size by 1
            heights.resize(n);
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1')
                    ++heights[j];
                else
                    heights[j] = 0;
            }
            res = max(res, largestRectangleInHistogram(heights));
        }
        return res;
    }

    int largestRectangleInHistogram(vector<int>& h)
    {
        h.push_back(0);
        stack<int> s;
        int res = 0;
        for(int i = 0; i < h.size(); ++i) {
            while(!s.empty() && h[s.top()] > h[i]) {
                int cur = s.top();
                s.pop();
                res = max(res, h[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }


  private:
};
