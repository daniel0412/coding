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

class FindDuplicateNumber {
  public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0, fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        int found = 0;
        while(found != slow) {
            found = nums[found];
            slow = nums[slow];
        }
        return found;
    }

  private:
};
