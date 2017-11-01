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

class LargestRectangeInHistogram {
  public:
    int largestRectangleArea(vector<int>& heights)
    {
        return stackImpl(heights);
    }

    int stackImpl(vector<int>& heights)
    {
        int res = 0;
        stack<int> s;
        // push in 0 height, so the stack will be emptyed at the end
        heights.push_back(0);

        for(int i = 0; i < heights.size(); ++i) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                int cur = s.top();
                s.pop();
                res = max(res,
                          heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }

    int timeoutImpl(vector<int>& heights)
    {
        int res = 0;

        for(int i = 0; i < heights.size(); ++i) {
            int h = heights[i];
            int w = 1;
            int j = i;
            while(--j >= 0 && heights[j] >= h)
                ++w;
            j = i;
            while(++j < heights.size() && heights[j] >= h)
                ++w;
            res = max(res, w * h);
        }
        return res;
    }

  private:
};
