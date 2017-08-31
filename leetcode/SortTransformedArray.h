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

class SortTransformedArray {
  public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c)
    {
        vector<int> res(nums.size(), 0);
        if(nums.empty())
            return res;
        int j = 0, k = nums.size() - 1;
        if(a == 0) {
            while(j <= k) {
                res[j] = calc(a, b, c, nums[j]);
                ++j;
            }
        }
        else {
            int id = a > 0 ? k : j;
            double mid = -0.5 * b / a;
            while(j <= k) {
                int x = abs(nums[j] - mid) > abs(nums[k] - mid) ? nums[j++] :
                                                                  nums[k--];
                res[id] = calc(a, b, c, x);
                id = a > 0 ? id - 1 : id + 1;
            }
        }
        return res;
    }

  private:
    int calc(const int a, const int b, const int c, const int x)
    {
        return a * x * x + b * x + c;
    }
};
