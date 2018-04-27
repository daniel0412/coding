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

class PartitionToKEqualSum {
  public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k)
            return false;
        // start from the largest number to reduce time cost
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> targets(k, 0);
        return recursiveImpl(nums, sum / k, targets, 0);
    }

  private:
    bool recursiveImpl(const vector<int>& nums,
                       const int target,
                       vector<int>& targets,
                       int id)
    {
        if(id >= nums.size()) {
            for(auto t : targets) {
                if(t != target)
                    return false;
            }
            return true;
        }
        for(int i = 0; i < targets.size(); ++i) {
            targets[i] += nums[id];
            if(targets[i] <= target) {
                if(recursiveImpl(nums, target, targets, id + 1))
                    return true;
            }
            targets[i] -= nums[id];
        }
        return false;
    }
};
