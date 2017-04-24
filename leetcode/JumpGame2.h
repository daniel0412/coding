/* 45. Jump Game II
 *
 * Given an array of non-negative integers, you are initially positioned at the
 *first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 *position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 *index 0 to 1, then 3 steps to the last index.)
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class JumpGame2 {
  public:
    int jump(vector<int>& nums)
    {
        int curId = 0, prevId = 0, i = 0;
        int numJumps = 0;
        while(curId < nums.size() - 1) {
            prevId = curId;
            while(i <= prevId) {
                int tmpId = i + nums[i];
                curId = curId > tmpId ? curId : tmpId;
                ++i;
            }
            if(prevId == curId)
                return -1;
            ++numJumps;
        }
        return numJumps;
    }

  private:
};
