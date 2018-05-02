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

class NondecreasingArray {
  public:
    bool checkPossibility(vector<int>& nums)
    {
        if(nums.size() < 3)
            return true;
        int cnt = 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(cnt == 0)
                    return false;
                // if it is the first element
                if(i == 0) {
                    nums[i] = nums[i + 1];
                }
                else {
                    if(nums[i - 1] < nums[i + 1]) {
                        nums[i] = nums[i - 1];
                    }
                    else {
                        nums[i + 1] = nums[i];
                    }
                }
                --cnt;
            }
        }
        return true;
    }


private:
}
;
