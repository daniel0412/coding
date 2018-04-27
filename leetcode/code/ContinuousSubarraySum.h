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

class ContinuousSubarraySum {
  public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> modToIndex{{0, -1}};
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int m = (k == 0) ? sum : sum % k;
            if(modToIndex.count(m)) {
                if(i - modToIndex[m] > 1) {
                    cout << "i: " << i << ", mod: " << modToIndex[m] << endl;
                    return true;
                }
            }
            else {
                modToIndex[m] = i;
            }
        }
        return false;
    }

  private:
};
