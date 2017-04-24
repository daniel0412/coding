/* 55. Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the
 *first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 *position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
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

class JumpGame {
  public:
    bool canJump(vector<int>& nums)
    {
        int maxId = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > maxId || maxId >= nums.size() - 1)
                break;
            int id = i + nums[i];
            maxId = maxId > id ? maxId : id;
        }
        return maxId >= nums.size() - 1;
    }

  private:
};
