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

class RandomPickIndex {
  public:
    RandomPickIndex(vector<int> nums) : d_nums(nums) {}

    int pick(int target)
    {
        int cnt = 1, res = -1;
        for(int i = 0; i < d_nums.size(); ++i) {
            // only apply sampling when target is found
            if(d_nums[i] == target) {
                if(rand() % cnt == 0) {
                    res = i;
                }
                ++cnt;
            }
        }
        return res;
    }

  private:
    vector<int> d_nums;
};
