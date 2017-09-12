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

class NextPermutation {
  public:
    void nextPermutation(vector<int>& nums)
    {
        if(nums.size() <= 1)
            return;
        stack<int> s;
        int id = nums.size() - 1;
        // find first decreasing number
        while(nums[id - 1] >= nums[id] && id > 0) {
            s.push(id--);
        }
        if(id == 0) {
            sort(nums.begin(), nums.end());
        }
        else {
            --id;
            // find first number larger than the found number
            int tmpId = nums.size() - 1;
            while(nums[tmpId] <= nums[id]) {
                --tmpId;
            }
            swap(nums[id], nums[tmpId]);
            // reverse the back sequence numbers
            reverse(nums.begin() + id + 1, nums.end());
        }
    }

  private:
};
