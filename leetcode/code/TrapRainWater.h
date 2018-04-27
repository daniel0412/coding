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

class TrapRainWater {
  public:
      // monotonic decreasing stack of indices
    int trap(vector<int>& height)
    {
        if(height.size() < 2)
            return 0;
        stack<int> s;
        int l = 0, r = height.size();
        int res = 0;
        while(l < r) {
            if(s.empty() || height[l] <= height[s.top()]) {
                s.push(l++);
            }
            else {
                int t = s.top();
                s.pop();
                if(s.empty())
                    continue;
                res += (l - s.top() - 1) *
                    (min(height[s.top()], height[l]) - height[t]);
            }
        }
        return res;
    }
    // two pointer
    int trap(vector<int>& height)
    {
        if(height.size() < 2)
            return 0;
        int l = 0, r = height.size() - 1, res = 0;
        while(l < r) {
            int mh = min(height[l], height[r]);
            if(mh == height[l]) {
                ++l;
                while(l < r && height[l] <= mh) {
                    res += (mh - height[l++]);
                }
            }
            else {
                --r;
                while(l < r && height[r] <= mh) {
                    res += (mh - height[r--]);
                }
            }
        }
        return res;
    }

  private:
};
