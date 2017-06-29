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

class ProductArrayExceptSelf {
  public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        if(nums.empty())
            return nums;
        if(nums.size() == 1)
            return vector<int>({1});

        vector<int> res(nums.size(), 0);
        res.back() = 1;
        for(int i = nums.size() - 1; i > 0; --i) {
            res[i - 1] = res[i] * nums[i];
        }
        int preProd = 1;
        for(int i = 1; i < nums.size(); ++i) {
            preProd *= nums[i - 1];
            res[i] *= preProd;
        }
        return res;
    }

  private:
};
