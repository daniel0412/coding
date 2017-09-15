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

class MaxConsecutiveOnes {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int maxcnt = 0;
        int cnt = 0;
        for(auto n : nums) {
            if(n == 1)
                ++cnt;
            else {
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
        }
        return maxcnt > cnt ? maxcnt : cnt;
    }

  private:
};
