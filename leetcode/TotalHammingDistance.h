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

class TotalHammingDistance {
  public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < 32; ++i) {
            int cnt = 0;
            for(auto num : nums) {
                if(num & (1 << i)) ++cnt;
            }
            res += (cnt * (n-cnt));
        }
        return res;
    }

  private:
};
