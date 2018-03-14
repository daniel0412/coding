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
    vector<int> sortTransformedArrayII(vector<int>& nums, int a, int b, int c)
    {
        if(nums.empty())
            return {};
        vector<int> res(nums.size(), 0);
        int i = 0, j = nums.size() - 1;
        // populate result startint index rely on the sign of a
        int startId = a > 0 ? j : 0;
        while(i <= j) {
            int ires = calc(a, b, c, nums[i]);
            int jres = calc(a, b, c, nums[j]);
            // when a = 0, it can be merged into either case
            if(a > 0) {
                if(ires >= jres) {
                    ++i;
                    res[startId--] = ires;
                }
                else {
                    --j;
                    res[startId--] = jres;
                }
            }
            else {
                if(ires >= jres) {
                    res[startId++] = jres;
                    --j;
                }
                else {
                    res[startId++] = ires;
                    ++i;
                }
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
